/*
This file is part of FAgram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

namespace Core {
class FileLocation;
} // namespace Core

namespace Media {
namespace Clip {

bool CheckStreamingSupport(
	const Core::FileLocation &location,
	QByteArray data);

} // namespace Clip
} // namespace Media
