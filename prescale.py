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
      if run not in self.data.keys():
        self.data[run]={}
      # second key is the lumisection from which the prescale starts
      ls=linesplit[1]
      prescale=linesplit[3]
      if ls=="None": 
        ls="1" 
      self.data[run][ls] = float(prescale)
   
  def getPrescale(self, run, lumi):
    if str(run) in self.data.keys():
      prescaleTable = self.data[str(run)]
      distance=999999
      closest="0"
      for ls in prescaleTable.keys():
        if lumi-int(ls)>0 and lumi-int(ls)<distance:
          distance = lumi-int(ls)
          closest = ls
      return prescaleTable[closest]      

    else:
      print "this run was not found for this trigger"
      return 1

  def getPrescaleWeight(self, run, lumi):
    return 1./self.getPrescale(run, lumi)

   



if __name__ == "__main__":
  prescale=Prescales('data/prescalesHLT_BTagMu_DiJet110_Mu5.txt')
  a=prescale.data['283685']
  print a
  print prescale.getPrescale(283685, 56)
