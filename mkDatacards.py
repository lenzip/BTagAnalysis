from optparse import OptionParser
import os
import ROOT
import sys

usage = "usage: %prog filenamedata filenamemc bin variable tagger"
parser = OptionParser(usage=usage)
parser.add_option("-o", "--output", dest="output", help='the output datacards directory, default "datacards"', default='datacards')
parser.add_option("-s", "--systematicsFile", dest="systematicsFile", help="the file containing the systematic variations", default='systematics.py')

#parser.add_option("-v", "--variable", dest="variable", help="the variable for which to build the datacards bin")

(options, args) = parser.parse_args()
if len(args) != 4:
    print(parser.print_help())
    sys.exit(1)
filenamedata=args[0]
filenamemc=args[1]
bin=args[2]
#variable=args[3]
tagger=args[3]

if os.path.exists(options.systematicsFile) :
    handle = open(options.systematicsFile,'r')
    exec(handle.read())
    handle.close()
allSysts = weightSystematics + shapeSystematics

processes = ['b', 'c', 'l']
categories = [tagger+'_SV', tagger+'_NoSV', tagger+'_Fail_SV',  tagger+'_Fail_NoSV']
yieldsData={}
yieldsMC={}
paths={}

variables = ['events', 'SVmass']

for variable in variables:
    paths[variable]={}
    for category in categories:
        if "_NoSV" in category and "SVmass" in variable: continue
        name=f"{options.output}/{tagger}/{bin}/{variable}/{category}"
        paths[variable][category] = name
        try:
            os.makedirs(f'{name}/shapes/')
        except FileExistsError:
            print(f"Warning: directory {name} exists")  
            pass  

    inFileData = ROOT.TFile.Open(filenamedata)
    inFileMC = ROOT.TFile.Open(filenamemc)

    yieldsData[variable] = {}
    yieldsMC[variable] = {}
    for category in categories:
        if "_NoSV" in category and "SVmass" in variable: continue
        outFile = ROOT.TFile.Open(f"{paths[variable][category]}/shapes/histos.root", 'recreate')
        #print(f"{variable}__{bin}_{category}")
        histoData = inFileData.Get(f"{variable}__{bin}_{category}")
        histoData.SetNameTitle("histo_Data", "histo_Data")
        outFile.cd()
        histoData.Write()
        yieldsData[variable][category] = histoData.Integral()
        yieldsMC[variable][category] = {}
        for process in processes:
            name=f"{variable}__{bin}_{process}_{category}"
            #print(name)
            histoMC = inFileMC.Get(name)
            outFile.cd()
            histoMC.SetNameTitle(f"histo_{process}", f"histo_{process}")
            yieldsMC[variable][category][process] = histoMC.Integral()
            histoMC.Scale(1./histoMC.Integral())
            histoMC.Write()
            for syst in allSysts:
                for var in ['up', 'do']:
                    #print (f'{name}_{syst}_{var}')
                    histoMC = inFileMC.Get(f'{name}_{syst}_{var}')
                    if (var=='up'):
                        var = 'Up'
                    else:
                        var="Down"    
                    histoMC.SetNameTitle(f"histo_{process}_{syst}{var}", f"histo_{process}_{syst}{var}")
                    outFile.cd()
                    histoMC.Scale(1./yieldsMC[variable][category][process])
                    histoMC.Write() 
totals={}
trueMCtagEff={}
trueMCsvEff_tag={}
trueMCsvEff_failtag={}
for process in processes:
    totals[process]=yieldsMC['events'][tagger+"_SV"][process]+yieldsMC['events'][tagger+"_NoSV"][process] + yieldsMC['events'][tagger+"_Fail_SV"][process]+yieldsMC['events'][tagger+"_Fail_NoSV"][process]
    trueMCtagEff[process]= (yieldsMC['events'][tagger+"_SV"][process]+yieldsMC['events'][tagger+"_NoSV"][process])/\
                            (yieldsMC['events'][tagger+"_SV"][process]+yieldsMC['events'][tagger+"_NoSV"][process] + yieldsMC['events'][tagger+"_Fail_SV"][process]+yieldsMC['events'][tagger+"_Fail_NoSV"][process]) 
    trueMCsvEff_tag[process]= (yieldsMC['events'][tagger+"_SV"][process])/\
                              (yieldsMC['events'][tagger+"_SV"][process]+yieldsMC['events'][tagger+"_NoSV"][process])                    
    trueMCsvEff_failtag[process]= (yieldsMC['events'][tagger+"_Fail_SV"][process])/\
                          (yieldsMC['events'][tagger+"_Fail_SV"][process]+yieldsMC['events'][tagger+"_Fail_NoSV"][process])

#print(yieldsMC)
print(trueMCtagEff)
print(trueMCsvEff_tag)
print(trueMCsvEff_failtag)
for variable in variables:
    for category in categories:
        if "_NoSV" in category and "SVmass" in variable: continue
        cardPath = f"{paths[variable][category]}/datacard.txt"
        card = open( cardPath ,"w")
        card.write('## Shape input card\n')
            
        card.write('imax 1 number of channels\n')
        card.write('jmax * number of background\n')
        card.write('kmax * number of nuisance parameters\n') 

        card.write('-'*100+'\n')
        columndef = 30
        card.write('bin          '+category+"\n")
        card.write('observation  '+str(yieldsData[variable][category])+"\n")
        card.write('shapes  *           * '+
                    'shapes/histos.root' +
                    '     histo_$PROCESS histo_$PROCESS_$SYSTEMATIC' + '\n')
                
        card.write('shapes  data_obs           * '+
                'shapes/histos.root' +
                '     histo_Data' + '\n')
        card.write('bin'.ljust(60))
        card.write(''.join([category.ljust(columndef)] * (len(processes)))+'\n')

        columndef = 30         
        card.write('process'.ljust(60))
        card.write(''.join(process.ljust(columndef) for process in processes))
        card.write('\n')

        card.write('process'.ljust(60))
        card.write(''.join(('%d' % (i)).ljust(columndef) for i,process in enumerate(processes)))
        card.write('\n')

        card.write('rate'.ljust(60))
        #card.write(''.join(('%-.4f' % yieldsMC[variable][category][process]).ljust(columndef) for process in processes))
        card.write(''.join('1.'.ljust(columndef) for process in processes))
        card.write('\n')

        card.write('-'*100+'\n')
        for nuisance in allSysts:
            card.write(nuisance.ljust(40)+'shape'.ljust(20))
            card.write(''.join('1.0'.ljust(columndef) for process in processes))
            card.write('\n')
        for process in processes:
            #if process != "b":
            card.write(f'norm_{process} rateParam {category} {process} {totals[process]}\n')
            if category == tagger+'_SV':
                card.write(f'eps_T_{process} rateParam {category} {process} {trueMCtagEff[process]} [0.,1.]\n')
                card.write(f'eps_VT_{process} rateParam {category} {process} {trueMCsvEff_tag[process]} [0.,1.]\n')
            if category == tagger+'_NoSV':
                card.write(f'eps_T_{process} rateParam {category} {process} {trueMCtagEff[process]} [0.,1.]\n')
                card.write(f'eps_nVT_{process} rateParam {category} {process} (1.-@0) eps_VT_{process}\n')
            if category == tagger+'_Fail_SV':
                card.write(f'eps_nT_{process} rateParam {category} {process} (1.-@0) eps_T_{process}\n')
                card.write(f'eps_VnT_{process} rateParam {category} {process} {trueMCsvEff_failtag[process]} [0.,1.]\n')
            if category == tagger+'_Fail_NoSV':
                card.write(f'eps_nT_{process} rateParam {category} {process} (1.-@0) eps_T_{process}\n')
                card.write(f'eps_nVnT_{process} rateParam {category} {process} (1.-@0) eps_VnT_{process}\n')
                




                



