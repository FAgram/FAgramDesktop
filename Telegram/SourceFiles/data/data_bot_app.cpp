/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#include "data/data_bot_app.h"

BotAppData::BotAppData(not_null<Data::Session*> owner, const BotAppId &id)
: owner(owner)
, id(id) {
}
