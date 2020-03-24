# Go Notes

#### Import Libraries or modules or packages

There is no such thing as local packages in Go. While local imports are possible to some extent, they're meant more for the Go devs themselves than for Go users.
Anything you import is relative to your `$GOPATH/src`. Thus, if you have a directory structure like the following one:

```sh
.
└── src
    └── gopher
        ├── main.go
        └── sub
            └── sub.go
```

in your `main.go` file you'll need to import sub as follows:

```go
package main
import "gopher/sub"
func main() {
    sub.ExportedFunction()
}
```

If you'd like to use a go package that's publicly available from some code hosting site, the recommended approach is to import it like this:

```go
import "github.com/path/to/package"
func main() {
    package.ExportedFunction()
}
```

Go tool let's you download remote packages either by passing their import path to `go get` or calling `go get ./...` inside your project's directory to recursively get all remote dependencies.

```sh
go get github.com/path/to/package
```

The source for the downloaded package will end up in `$GOPATH/src/github.com/path/to/package`. Go tool will also automatically build a static lib and put it in `$GOPATH/pkg/...`. To read more about this, run `go help get` and `go help gopath`.

#### how to import modules?


#### Golang Code Organization for Multi Language Project

for simple go package project you can use default $GOPATH
for multilanguage application project you can use following structure (you have to change $GOPATH) 

```sh
.
└── Project 
    ├── GoProjects - $GOPATH
    │	├── src
    │	│	├── gomodule1
    │	│	├── gomodule2
    │	│	├── gomodule3
    │   │   │   ├── some.go
    │   │   │   ├── some_test.go
    │   │   │   ├── main
    │   │   │   │   ├── main.go //package main; import "gomodule1"
    │	├── bin
    │	└── pkg
    ├── OtherProject
    ├── README.md
    ├── build.bat
    └── build.sh
```

### todo
go mod file and go sum file


refer https://github.com/alco/gostart for more