class Prescales:
  def __init__(self, csvFile):
    self.csvFile = csvFile
    self._load()

  def _load(self):
    filein = open(self.csvFile)
    self.data={}
    for line in filein:
      if "totprescval" in line:
        continue
      linesplit=line.split(',')
      # first key is run number
      run=linesplit[0]
      if run not in list(self.data.keys()):
        self.data[run]={}
      # second key is the lumisection from which the prescale starts
      ls=linesplit[1]
      prescale=linesplit[3]
      if ls=="None": 
        ls="1" 
      self.data[run][ls] = float(prescale)
   
  def getPrescale(self, run, lumi):
    if str(run) in list(self.data.keys()):
      prescaleTable = self.data[str(run)]
      distance=999999
      closest="1"
      for ls in list(prescaleTable.keys()):
        if lumi-int(ls)>=0 and lumi-int(ls)<distance:
          distance = lumi-int(ls)
          closest = ls
      if closest != "0": 
        return prescaleTable[closest]      
      else:
        print("Warning: prescale table requested for ls 0. This should not happen. Run", run, "lumi", lumi, "file", self.csvFile) 
        return 1.
      

    else:
      print("this run was not found for this trigger")
      return 1

  def getPrescaleWeight(self, run, lumi):
    return self.getPrescale(run, lumi)

   



if __name__ == "__main__":
  prescale=Prescales('data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet40_Mu5.txt')
  a=prescale.data['362695']
  print(a)
  print(prescale.getPrescale(362695, 4))
