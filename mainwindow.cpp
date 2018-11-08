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

#include "mainwindow.h"
#include "Popup_AddColumn.h"

MainWindow::MainWindow()
{
    createMenu();
    createQuickMenuGroupBox();
    createTableGroupBox();


    QHBoxLayout *mainLayout = new QHBoxLayout;

    mainLayout->setMenuBar(menuBar);

    mainLayout->addWidget(verticalGroupBox);
    mainLayout->addWidget(gridGroupBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Basic Layouts"));
}


void MainWindow::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}


//Creates the QuickMenu area on the main page
void MainWindow::createQuickMenuGroupBox()
{
    verticalGroupBox = new QGroupBox(tr("Quick Menu"));
    QVBoxLayout *layout = new QVBoxLayout;


    //Initialize all quick menu buttons
    newRowButton = new QPushButton(tr("Add New Row"), this);
    connect(newRowButton, SIGNAL (pressed()), this, SLOT (on_newRowButton_clicked()));
    newColButton = new QPushButton(tr("Add new Column"), this);
    connect(newColButton, SIGNAL (pressed()), this, SLOT (on_newColButton_clicked()));
    delSelectedRow = new QPushButton(tr("Delete Selected Row"), this);
    connect(delSelectedRow, SIGNAL (pressed()), this, SLOT (on_delSelectedRow_clicked()));
    delCol = new QPushButton(tr("Delete A Column"), this);
    connect(delCol, SIGNAL (pressed()), this, SLOT (on_delCol_clicked()));

    //Add buttons to quick menu layout
    layout->addWidget(newRowButton);
    layout->addWidget(newColButton);
    layout->addWidget(delSelectedRow);
    layout->addWidget(delCol);

    verticalGroupBox->setLayout(layout);
}


//Creates the Table that is displayed on the main screen
void MainWindow::createTableGroupBox()
{
    gridGroupBox = new QGroupBox(tr("Table View"));
    QGridLayout *layout = new QGridLayout;

    tableView = new QTableWidget();

    layout->addWidget(tableView, 0, 0, 4, 1);

    gridGroupBox->setLayout(layout);
}

void MainWindow::on_newRowButton_clicked()
{
    tableView->insertRow(tableView->rowCount());
}

void MainWindow::on_newColButton_clicked()
{
    int index = tableView->columnCount();

    Popup_AddColumn *columnDialog = new Popup_AddColumn();

    columnDialog->show();
    columnDialog->raise();
    columnDialog->activateWindow();

    //tableView->insertColumn(index);
    //tableView->setHorizontalHeaderItem(index, new QTableWidgetItem(tr("TEST")));
}

void MainWindow::on_delSelectedRow_clicked()
{
    tableView->removeRow(tableView->currentRow());
}

void MainWindow::on_delCol_clicked()
{
    tableView->removeColumn(tableView->currentColumn());
}
