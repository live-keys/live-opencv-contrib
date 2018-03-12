/****************************************************************************
**
** Copyright (C) 2014-2017 Dinu SV.
** (contact: mail@dinusv.com)
** This file is part of Live CV Application.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
****************************************************************************/

#include "briefdescriptorextractor.h"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"

namespace lv{

BriefDescriptorExtractor::BriefDescriptorExtractor(QQuickItem *parent)
    : QDescriptorExtractor(cv::xfeatures2d::BriefDescriptorExtractor::create(), parent)
{
}

BriefDescriptorExtractor::~BriefDescriptorExtractor(){
}

void BriefDescriptorExtractor::initialize(const QVariantMap &params){
    int bytes = 32;
    bool useOrientation = false;

    if ( params.contains("bytes") )
        bytes = params["bytes"].toInt();
    if ( params.contains("useOrientation") )
        useOrientation = params["useOrientation"].toBool();

    initializeExtractor(cv::xfeatures2d::BriefDescriptorExtractor::create(bytes, useOrientation));
}

}// namespace
