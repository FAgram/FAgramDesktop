/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/

#pragma once

#include "settings/settings_common.h"
#include "settings/settings_common_session.h"
#include <QLabel>
#include <QSlider>

class BoxContent;

namespace Window {
    class Controller;
    class SessionController;
} // namespace Window

namespace Settings {
    class FAAppearance : public Section<FAAppearance> {
    public:
        FAAppearance(QWidget *parent, not_null<Window::SessionController *> controller);

        [[nodiscard]] rpl::producer<QString> title() override;

    private:
        void SetupAppearance(not_null<Ui::VerticalLayout *> container);
        void SetupFAAppearance(not_null<Ui::VerticalLayout *> container, not_null<Window::SessionController *> controller);
        void setupContent(not_null<Window::SessionController *> controller);

        QLabel *userpicRoundnessLabel;
        QLabel *roundnessPreview;
        QSlider *userpicRoundnessSlider;
    };

} // namespace Settings
