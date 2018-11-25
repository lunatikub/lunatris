Lunatris
========

[![Build Status](https://travis-ci.org/lunatikub/lunatris.svg?branch=master)](https://travis-ci.org/lunatikub/lunatris)

Tetris Bot with AI.

# Table of content

- [Getting Started](#section-id-8)
  - [Prerequisites](#section-id-10)
    - [Getting Meson](#section-id-15)
    - [Ninja](#section-id-24)
    - [Installing Meson with pip](#section-id-35)
  - [Installing](#section-id-44)
- [2. Running the tests](#section-id-66)
- [Built with](#section-id-81)
- [Contributing](#section-id-85)
- [License](#section-id-89)

<div id='section-id-8'/>

# Getting Started

<div id='section-id-10'/>

## Prerequisites

We are using the [Meson Build System](https://mesonbuild.com/index.html) to build **lunatris** project.
Meson is an open source build system meant to be both extremely fast, and even more importantly, as user friendly as possible.

<div id='section-id-15'/>

### Getting Meson

Meson is implemented in Python 3, and requires 3.5 or newer. If your operating system provides a package manager, you should install it with that.

``` bash
apt-get install python3 python3-pip
yum install python3 python3-pip
```

<div id='section-id-24'/>

### Ninja

Meson needs the [ninja](https://ninja-build.org/) executable.
It is a small build system with a focus on speed.
You can use the version provided by your package manager if possible, otherwise download the binary executable from the Ninja project's release page.

``` bash
apt-get install ninja
yum install ninja
```

<div id='section-id-35'/>

### Installing Meson with pip

You can use the following to install meson for your user and does not require any special privileges.
This will install the package in **~/.local/**, so you will have to add **~/.local/bin** to your PATH.

``` bash
pip3 install --user meson
```

<div id='section-id-44'/>

## Installing

Create a build directory by the simple following command from the root directory.

``` bash
meson <build-dir-name>
```

Compile the **lunatris** project.

``` bash
cd <build-dir-name>
ninja
```

Install the **lunatris** project.

``` bash
cd <build-dir-name>
ninja install
```

<div id='section-id-66'/>

# Running the tests

To run all the tests.

``` bash
cd <build-dir-name>
ninja test
```

<div id='section-id-81'/>

# Built with

* [googletest](https://github.com/abseil/googletest): google Test is a unit testing library for the C/C++ programming language.

<div id='section-id-85'/>

# Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

<div id='section-id-89'/>

# License

This project is under a proprietary License - see the [LICENSE](LICENSE) file for details.
