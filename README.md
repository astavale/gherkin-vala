| Platform | Status |
| --- | --- | 
| Fedora 22 | [![Build Status](http://jenkins.valadate.org:8080/buildStatus/icon?job=Gherkin for Vala (Fedora))](http://jenkins.valadate.org:8080/job/Gherkin%20for%20Vala%20(Fedora)/) |
| Ubuntu 15.04 | [![Build Status](http://jenkins.valadate.org:8080/buildStatus/icon?job=Gherkin for Vala (Ubuntu 15.04))](http://jenkins.valadate.org:8080/job/Gherkin%20for%20Vala%20(Ubuntu%2015.04)/) |
| Windows 7 | [![Build Status](http://jenkins.valadate.org:8080/buildStatus/icon?job=Gherkin for Vala (Win64))](http://jenkins.valadate.org:8080/job/Gherkin%20for%20Vala%20(Win64)/) |
| Mac OS X | [![Build Status](http://jenkins.valadate.org:8080/buildStatus/icon?job=Gherkin for Vala (Mac OSX))](http://jenkins.valadate.org:8080/job/Gherkin%20for%20Vala%20(Mac%20OSX)/) |

Gherkin parser/compiler for Vala. Please see [Gherkin3](https://github.com/cucumber/gherkin3) for details.

## Building from Source
`libgherkin3` uses `autotools` for the build process. For a fresh build, straight after `git` cloning this repository, do:
```
cd gherkin-vala
./autogen.sh
```
or
```
cd gherkin-vala
./autogen.sh --prefix /my/personal/directory/to/install/to
```
if you want to try out `libgherkin3` without a system wide install.
Then continue with:
```
make
make install
```
To run the test suite:
```
make test
```
