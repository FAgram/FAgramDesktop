/*
This file is part of FAgram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

namespace Data {

struct PeerSubscription final {
	uint64 credits = 0;
	int period = 0;

	explicit operator bool() const {
		return credits > 0 && period > 0;
	}
};

struct SubscriptionEntry final {
	explicit operator bool() const {
		return !id.isEmpty();
	}

	QString id;
	QString inviteHash;
	QDateTime until;
	PeerSubscription subscription;
	uint64 barePeerId = 0;
	bool cancelled = false;
	bool expired = false;
	bool canRefulfill = false;
};

} // namespace Data
