# Gradle Notes

Gradle is used for dependency management in Java projects, but we can also use it in other non-Java projects through plugins.

A Jar file is like a ZIP file, that may contain one or more files (mostly java classes) or directories. 

### Java Directory Structure
```bash
├── project
│   ├── src
│   │   ├── main
│   │   │   ├── java
│   │   │   │   ├── com.company.project
│   │   ├── test
│   │   │   ├── java
│   │   │   │   ├── com.company.projecttest
│   ├── resources
│   ├── gradle.build
```
	
##### Directories
**Directory src** - To separate resource folder & image and other files(e.g. gradle.build readme.md).
**Directory main** - To separate test directory
**Directory java** - One project could contain any number of language. e.g. kotlin and java
 
 
### Gradle

**build.gradle**

````groovy
apply plugin: "java"

sourceSets {
	main.java.srcDir "src/main"
	test.java.srcDir "src/test"
}

jar {
	manifest.attributes "Main-Class": "net.diamond.gradledoc.Main"
}
````
**Build the project**
```bash
    gradle build
```
**Execute jar file**
```bash
    java -jar build/libs/gradledoc.jar "Hello" "Gradle"
```