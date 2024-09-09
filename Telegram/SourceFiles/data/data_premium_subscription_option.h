/*
This file is part of FAgram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

namespace Data {

struct PremiumSubscriptionOption {
	QString duration;
	QString discount;
	QString costPerMonth;
	QString costTotal;
	QString total;
	QString botUrl;
};
using PremiumSubscriptionOptions = std::vector<PremiumSubscriptionOption>;

} // namespace Data
