/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

#include "ui/text/text_entity.h"

namespace Lang {

template <typename ResultString>
struct StartReplacements;

template <>
struct StartReplacements<TextWithEntities> {
	static inline TextWithEntities Call(QString &&langString) {
		return { std::move(langString), EntitiesInText() };
	}
};

template <typename ResultString>
struct ReplaceTag;

template <>
struct ReplaceTag<TextWithEntities> {
	static TextWithEntities Call(TextWithEntities &&original, ushort tag, const TextWithEntities &replacement);
	static TextWithEntities Replace(TextWithEntities &&original, const TextWithEntities &replacement, int start);

};

} // namespace Lang
