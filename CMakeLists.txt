cmake_minimum_required(VERSION 2.8)
project(finnigan-parser)

############
# UNTHERMO #
############

# Get and run Go unthermo project.

# TODO How to test that Go is present ?
set(ENV{GOPATH} $ENV{PWD})
execute_process(COMMAND go get bitbucket.org/proteinspector/ms/unthermo)
execute_process(COMMAND go run src/bitbucket.org/proteinspector/ms/unthermo/tools/printspectrum.go -sn 1 -raw ../test/res/20150403_G46_N1060_NEG_Test.raw)
find_package(Git)
if(GIT_FOUND)
#	execute_process(COMMAND ${GIT_EXECUTABLE} clone git@bitbucket.org:proteinspector/ms.git)
# TODO remplacer par un appel avec go:
# GOPATH=$(pwd) go get bitbucket.org/proteinspector/ms/unthermo
#	execute_process(COMMAND go install )
# GOPATH=$(pwd) go run src/bitbucket.org/proteinspector/ms/unthermo/tools/printspectrum.go -sn 1 -raw test/res/20150403_G46_N1060_NEG_Test.raw
endif()
