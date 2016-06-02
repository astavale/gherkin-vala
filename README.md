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

## Getting Started
`gherkin-vala` provides three command line tools to get started:
 * `gherkin-generate-ast`
 * `gherkin-generate-pickles`
 * `gherkin-generate-tokens`

A Gherkin `.feature` file, after any comments, should start with the `Feature` keyword in the human language specified for that file. The default language is English. Save this very basic example as `test.feature`:

```
Feature: A meaningless example
```

Then run `gherkin-generate-ast` with the file:

```gherkin-generate-ast test.feature```

This will dump the abstract syntax tree as JSON:

```
{
  "node-type" : "Feature",
  "location" : {
    "line" : 1,
    "column" : 1
  },
  "tags" : [
  ],
  "language" : "en",
  "keyword" : "Feature",
  "name" : "A meaningless example",
  "scenarioDefinitions" : [
  ],
  "comments" : [
  ]
}
```

## `libgherkin3` API and ABI
`libgherkin3` was generated from the reference implementation, [gherkin](https://github.com/cucumber/gherkin), and follows that API. Work currently needs to be done on marking internal functions as `internal` in Vala and also developing a stable ABI. Anyone wanting to work on the API/ABI should read:

 * [Libraries in Vala – ABI compatibility – part I](https://blog.piechotka.com.pl/2013/07/30/libraries-in-vala-abi-compatibility-part-i/)
 * [Libraries in Vala – ABI compatibility – part II](https://blog.piechotka.com.pl/2013/12/20/libraries-in-vala-abi-compatibility-part-ii/)
