/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

#include "mtproto/sender.h"

class ApiWrap;

namespace Window {
class SessionController;
} // namespace Window

namespace Api {

class ConfirmPhone final {
public:
	explicit ConfirmPhone(not_null<ApiWrap*> api);

	void resolve(
		not_null<Window::SessionController*> controller,
		const QString &phone,
		const QString &hash);

private:
	MTP::Sender _api;
	mtpRequestId _sendRequestId = 0;
	mtpRequestId _checkRequestId = 0;

};

} // namespace Api
