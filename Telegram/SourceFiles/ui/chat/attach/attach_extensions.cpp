/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#include "ui/chat/attach/attach_extensions.h"

#include <QtCore/QMimeDatabase>
#include <QtGui/QImageReader>

namespace Ui {

const QStringList &ImageExtensions() {
	static const auto result = [] {
		const auto formats = QImageReader::supportedImageFormats();
		return formats | ranges::views::transform([](const auto &format) {
			return '.' + format.toLower();
		}) | ranges::views::filter([](const auto &format) {
			const auto mimes = QMimeDatabase().mimeTypesForFileName(
				u"test"_q + format);
			return !mimes.isEmpty()
				&& mimes.front().name().startsWith(u"image/"_q);
		}) | ranges::to<QStringList>;
	}();
	return result;
}

} // namespace Ui
