/*
 *  This file is part of Manjaro Settings Manager.
 *
 *  Roland Singer <roland@manjaro.org>
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

#ifndef PAGEUSERS_H
#define PAGEUSERS_H

#include "AddUserDialog.h"
#include "ChangePasswordDialog.h"
#include "AccountTypeDialog.h"
#include "PreviewFileDialog.h"
#include "PageWidget.h"
#include "UsersCommon.h"

#include <QIcon>
#include <QPixmap>
#include <QFile>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QMessageBox>

#include <unistd.h>
#include <pwd.h>
#include <grp.h>


namespace Ui
{
class PageUsers;
}


class PageUsers : public PageWidget
{
    Q_OBJECT

public:
    explicit PageUsers( QWidget* parent = 0 );
    ~PageUsers();

    void load();

private:
    class ListWidgetItem : public QListWidgetItem
    {
    public:
        ListWidgetItem( QListWidget* parent ) : QListWidgetItem( parent ) {}
        UsersCommon::User user;
    };

    Ui::PageUsers* ui;

private slots:
    void setupUserData( QListWidgetItem* current );
    void buttonImage_clicked();
    void buttonAddUser_clicked();
    void buttonRemoveUser_clicked();
    void buttonChangePassword_clicked();
    void buttonChangeAccountType_clicked();

};

#endif // PAGEUSERS_H
