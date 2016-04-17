/*
 *  This file is part of Manjaro Settings Manager.
 *
 *  Roland Singer <roland@manjaro.org>
 *  Ramon Buldó <ramon@manjaro.org>
 *
 *  Manjaro Settings Manager is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Manjaro Settings Manager is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Manjaro Settings Manager.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PAGELANGUAGEPACKAGES_H
#define PAGELANGUAGEPACKAGES_H

#include "ApplyDialog.h"
#include "LanguagePackages.h"
#include "LanguagePackagesItem.h"
#include "PageWidget.h"

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMap>
#include <QMapIterator>
#include <QMessageBox>


namespace Ui
{
class PageLanguagePackages;
}


class PageLanguagePackages : public PageWidget
{
    Q_OBJECT

public:
    explicit PageLanguagePackages( QWidget* parent = 0 );
    ~PageLanguagePackages();

    void load();
    void save();

private:
    Ui::PageLanguagePackages* ui;

    void loadLanguagePackages();
    void loadNotificationsSettings();
    QTreeWidgetItem* newParentTreeWidgetItem( QTreeWidget* parent );
};

#endif // PAGELANGUAGEPACKAGES_H
