FINNIGAN PARSER
===============

**Finnigan parser** is C/C++ library and program parser for the Finnigan file format used by the ©Thermo Xcalibure software for its `.raw` files.

It is based on the project [unthermo](https://pkelchte.wordpress.com/2013/11/25/unthermo/) written in [Go](https://golang.org/), itself based on the project [unfinnigan](https://code.google.com/archive/p/unfinnigan/) written in Perl.

```bash
GOPATH=$(pwd) go get bitbucket.org/proteinspector/ms/unthermo
GOPATH=$(pwd) go run src/bitbucket.org/proteinspector/ms/unthermo/tools/printspectrum.go -sn 1 -raw test/res/20150403_G46_N1060_NEG_Test.raw >20150403_G46_N1060_NEG_Test.output
```
