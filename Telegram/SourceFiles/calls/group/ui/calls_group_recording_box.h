 /*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

namespace Ui {
class GenericBox;
} // namespace Ui

namespace Calls::Group {

enum class RecordingType {
	AudioOnly,
	VideoLandscape,
	VideoPortrait,
};

void EditGroupCallTitleBox(
	not_null<Ui::GenericBox*> box,
	const QString &placeholder,
	const QString &title,
	bool livestream,
	Fn<void(QString)> done);

void StartGroupCallRecordingBox(
	not_null<Ui::GenericBox*> box,
	Fn<void(RecordingType)> done);

void AddTitleGroupCallRecordingBox(
	not_null<Ui::GenericBox*> box,
	const QString &title,
	Fn<void(QString)> done);

void StopGroupCallRecordingBox(
	not_null<Ui::GenericBox*> box,
	Fn<void(QString)> done);

} // namespace Calls::Group
