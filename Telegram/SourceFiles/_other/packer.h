/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

#include <QtCore/QCoreApplication>
#include <QtCore/QFileInfo>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QStringList>
#include <QtCore/QBuffer>
#include <QtCore/QDataStream>

#include <zlib.h>

extern "C" {
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
} // extern "C"

#if defined Q_OS_WIN && !defined TDESKTOP_USE_PACKAGED // use Lzma SDK for win
#include <LzmaLib.h>
#else
#include <lzma.h>
#endif

#include <string>
#include <iostream>
#include <exception>

using std::string;
using std::wstring;
using std::cout;
