# Livekeys - OpenCV.Contrib Module

[![Join the chat at https://gitter.im/dinusv/livecv](https://badges.gitter.im/dinusv/livecv.svg)](https://gitter.im/dinusv/livecv?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Build Status](https://travis-ci.org/livecv/live-opencv-contrib.svg?branch=master)](https://travis-ci.org/livecv/live-opencv-contrib)
[![Build status](https://ci.appveyor.com/api/projects/status/i4nkpu49ublysep2?svg=true)](https://ci.appveyor.com/project/dinusv/live-opencv-contrib)

This plugin contains Open CV Contrib module QML wrappers that can be used for Livekeys.

 * **Version**: 1.0.0
 * **License**: LGPL + Non Commercial for a set of components (See below)
 * **Website**: [livekeys.io](https://livekeys.io/)
 * **Documentation**: [livekeys.io/docs](https://livekeys.io/docs/)
 * **Build Requirements**:
   * Qt 5.14 or higher
   * Open CV Contrib 4.1 or higher
   

## Installation and getting started

This module can be downloaded as part of Livekeys application from Livekeys' [website](https://livekeys.io/download).

## Compiling

To compile you need to have Qt and Open CV installed. You can then use qmake to generate the makefile, and run make or nmake to build:

```
cd build
qmake -r
make (or nmake)
```

Include the plugins within Livekeys' path/plugins, after which you can import them from Livekeys : (```import opencv.contrib.core 1.0```).

## Non Commercial Components

Within this package, some components (e.g SIFT and SURF) cannot be used commercially. To maintain its licensing, they are
not compiled within the release of this module, and you will have to compile them manually with the BUILD_NON_FREE flag set.

```
cd build
qmake -r "BUILD_NON_FREE=true"
make (or nmake)
```

## Contributing

The [organization on github](https://github.com/live-keys) is created for Livekeys plugins and projects, so anyone looking to contribute is always welcome. Check out [livekeys/CONTRIBUTING](https://github.com/live-keys/livekeys/blob/master/CONTRIBUTING.md) article for more info.
