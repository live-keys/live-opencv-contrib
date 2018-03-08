# Live CV - OpenCV.Contrib Module

[![Join the chat at https://gitter.im/dinusv/livecv](https://badges.gitter.im/dinusv/livecv.svg)](https://gitter.im/dinusv/livecv?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Build Status](https://travis-ci.org/livecv/live-opencv-contrib.svg?branch=master)](https://travis-ci.org/livecv/live-opencv-contrib)
[![Build status](https://ci.appveyor.com/api/projects/status/i4nkpu49ublysep2?svg=true)](https://ci.appveyor.com/project/dinusv/live-opencv-contrib)

This plugin contains Open CV Contrib module QML wrappers that can be used for Live CV.

 * **Version**: 1.0.0
 * **License**: LGPL
 * **Website**: [livecv.dinusv.com](http://livecv.dinusv.com)
 * **Documentation**: [livecv.dinusv.com/documentation](http://livecv.dinusv.com/documentation)
 * **Build Requirements**:
   * Qt 5.6 or higher
   * Open CV 3.1 or higher
   

## Installation and getting started

This module can be downloaded as part of Live CV application from Live CV's [website](http://livecv.dinusv.com/download.html).

## Compiling

To compile you need to have Qt and Open CV installed. You can then use qmake to generate the makefile, and run make or nmake to build:

```
cd build
qmake -r
make (or nmake)
```

Include the plugins within LiveCV's path/plugins after which you can import them from Live CV : (```import opencv.contrib.core 1.0```).

## Contributing

There's an [organization on github](http://github.com/livecv) created for Live CV plugins and projects, so anyone looking to contribute is always welcome. Check out livecv/CONTRIBUTING article for more info.

There's a forum available for discussions on [live cv's website](http://livecv.dinusv.com/forum).

