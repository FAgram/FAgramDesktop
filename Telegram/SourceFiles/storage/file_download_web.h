/*
This file is part of FAgram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

#include "storage/file_download.h"

class WebLoadManager;

class webFileLoader final : public FileLoader {
public:
	webFileLoader(
		not_null<Main::Session*> session,
		const QString &url,
		const QString &to,
		LoadFromCloudSetting fromCloud,
		bool autoLoading,
		uint8 cacheTag);
	~webFileLoader();

	[[nodiscard]] QString url() const;

	int64 currentOffset() const override;

private:
	void cancelRequest();
	void cancelHook() override;
	void startLoading() override;
	Storage::Cache::Key cacheKey() const override;
	std::optional<MediaKey> fileLocationKey() const override;

	void loadProgress(qint64 ready, qint64 size);
	void loadFinished(const QByteArray &data);
	void loadFailed();

	const QString _url;
	int64 _ready = 0;

	std::shared_ptr<WebLoadManager> _manager;
	rpl::lifetime _managerLifetime;

};
