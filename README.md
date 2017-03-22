Tool for histograms based on the BTagAnalyzer
=============================================

This is a common tool to plot variables and apply selections on top of the BTagAnalyzer. The main lorgram is loop.py, it is conficured via two additional files, cuts.py and variables.py

variables.py defines the variales to plot for each selection.

cuts.py defines a global event selection and a series of cuts. Jet pt categorization, or jet flavor categorization of algorithms can be configured and for each of them all the resulting cuts all the plotd in variables.py are performed.

Some of the commont event selections are implemente directly in loop.py because they cannot be implemented as a single string on top of the BTagAnalyzer module, e.g. the request of an identified muon to match a jet.

Other auxiliary classes for pileup reweighting (MC) and prescal normalization (data) have been added. Their use is exemplified in loop.py.
