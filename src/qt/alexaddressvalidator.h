// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Alex Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RAVEN_QT_RAVENADDRESSVALIDATOR_H
#define RAVEN_QT_RAVENADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class AlexAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AlexAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Alex address widget validator, checks for a valid alex address.
 */
class AlexAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AlexAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // RAVEN_QT_RAVENADDRESSVALIDATOR_H
