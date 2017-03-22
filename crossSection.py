class CrossSection:
  def __init__(self, inputFile):
    self.data={}
    for line in open(inputFile):
      if "#" in line: continue
      linesplit=line.rstrip('\n').split(",")
      self.data[linesplit[0]] = {}
      self.data[linesplit[0]]['xsec'] = float(linesplit[1])
      self.data[linesplit[0]]['filter'] = float(linesplit[2])
      self.data[linesplit[0]]['events'] = float(linesplit[3])
      self.data[linesplit[0]]['mcLumi'] = self.data[linesplit[0]]['events']/(self.data[linesplit[0]]['filter']*self.data[linesplit[0]]['xsec'])
    print self.data
      
  def getWeight(self, chain, dataLumi):
    filename = chain.GetFile().GetName()
    for key in self.data.keys():
      if key in filename:
        return dataLumi/self.data[key]['mcLumi']
    return 1.
