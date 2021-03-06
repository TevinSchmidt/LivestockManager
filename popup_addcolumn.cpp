/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "popup_addcolumn.h"


Popup_AddColumn::Popup_AddColumn()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;

    mainLayout->addWidget(verticalGroupBox);

    setLayout(mainLayout);
    setWindowTitle(tr("Create New Column"));
}

Popup_AddColumn::~Popup_AddColumn()
{
    delete mainWindow;
    delete verticalGroupBox;
    delete formBox;
    delete bottomOptionsBox;

    delete acceptButton;
    delete cancelButton;

    delete columnName;
}

void Popup_AddColumn::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void Popup_AddColumn::createWindow()
{
    verticalGroupBox = new QGroupBox();
    QVBoxLayout *layout = new QVBoxLayout;

    createForm();
    createBottomOptions();

    layout->addWidget(formBox);
    layout->addWidget(bottomOptionsBox);

}

void Popup_AddColumn::createForm()
{
    formBox = new QGroupBox();
    QGridLayout *layout = new QGridLayout;

    columnName = new QLineEdit();

    layout->addWidget(columnName);

    formBox->setLayout(layout);
}

void Popup_AddColumn::createBottomOptions()
{
    bottomOptionsBox = new QGroupBox();
    QHBoxLayout *layout = new QHBoxLayout;

    //Initialize buttons
    acceptButton = new QPushButton(tr("Accept"), this);
    connect(acceptButton, SIGNAL (pressed()), this, SLOT (on_acceptButton_clicked()));
    cancelButton = new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL (pressed()), this, SLOT (on_cancelButton_clicked()));

    //Add buttons to layout
    layout->addWidget(acceptButton);
    layout->addWidget(cancelButton);

    bottomOptionsBox->setLayout(layout);
}

void Popup_AddColumn::on_acceptButton_clicked()
{

}

void Popup_AddColumn::on_cancelButton_clicked()
{

}
