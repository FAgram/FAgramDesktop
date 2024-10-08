/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/

#include "fa/utils/fa_profile_values.h"

#include <QLocale>
#include <vector>
#include <algorithm>
#include <cmath>

constexpr auto kMaxChannelId = -1000000000000;

QString IDString(not_null<PeerData*> peer) {
    auto resultId = QString::number(peerIsUser(peer->id)
                                    ? peerToUser(peer->id).bare
                                    : peerIsChat(peer->id)
                                      ? peerToChat(peer->id).bare
                                      : peerIsChannel(peer->id)
                                        ? peerToChannel(peer->id).bare
                                        : peer->id.value);
    bool show_id_botapi = FASettings::JsonSettings::GetBool("show_id_botapi");
    if (show_id_botapi) {
        if (peer->isChannel()) {
            resultId = QString::number(peerToChannel(peer->id).bare - kMaxChannelId).prepend("-");
        } else if (peer->isChat()) {
            resultId = resultId.prepend("-");
        }
    }
    return resultId;
}
rpl::producer<TextWithEntities> IDValue(not_null<PeerData*> peer) {
    return rpl::single(IDString(peer)) | Ui::Text::ToWithEntities();
}

// suddenly stole into materialgram

QString parseRegistrationTime(QString prefix, long long regTime) {
	return prefix + base::unixtime::parse(regTime)
		.toString(QLocale::system().dateFormat(QLocale::ShortFormat));
}

QString findRegistrationTime(long long userId) {
	struct UserData {
		long long id;
		long long registrationTime;
	};
	std::vector<UserData> userData = {
		{1000000, 1380326400}, // 2013
		{2768409, 1383264000},
		{7679610, 1388448000},
		{11538514, 1391212000}, // 2014
		{15835244, 1392940000},
		{23646077, 1393459000},
		{38015510, 1393632000},
		{44634663, 1399334000},
		{46145305, 1400198000},
		{54845238, 1411257000},
		{63263518, 1414454000},
		{101260938, 1425600000}, // 2015
		{101323197, 1426204000},
		{103151531, 1433376000},
		{103258382, 1432771000},
		{109393468, 1439078000},
		{111220210, 1429574000},
		{112594714, 1439683000},
		{116812045, 1437696000},
		{122600695, 1437782000},
		{124872445, 1439856000},
		{125828524, 1444003000},
		{130029930, 1441324000},
		{133909606, 1444176000},
		{143445125, 1448928000},
		{148670295, 1452211000}, // 2016
		{152079341, 1453420000},
		{157242073, 1446768000},
		{171295414, 1457481000},
		{181783990, 1460246000},
		{222021233, 1465344000},
		{225034354, 1466208000},
		{278941742, 1473465000},
		{285253072, 1476835000},
		{294851037, 1479600000},
		{297621225, 1481846000},
		{328594461, 1482969000},
		{337808429, 1487707000}, // 2017
		{341546272, 1487782000},
		{352940995, 1487894000},
		{369669043, 1490918000},
		{400169472, 1501459000},
		{616816630, 1529625600}, // 2018
		{681896077, 1532821500},
		{727572658, 1543708800},
		{796147074, 1541371800},
		{925078064, 1563290000}, // 2019
		{928636984, 1581513420}, // 2020
		{1054883348, 1585674420},
		{1057704545, 1580393640},
		{1145856008, 1586342040},
		{1227964864, 1596127860},
		{1382531194, 1600188120},
		{1658586909, 1613148540}, // 2021
		{1660971491, 1613329440},
		{1692464211, 1615402500},
		{1719536397, 1619293500},
		{1721844091, 1620224820},
		{1772991138, 1617540360},
		{1807942741, 1625520300},
		{1893429550, 1622040000},
		{1972424006, 1631669400},
		{1974255900, 1634000000},
		{2030606431, 1631992680},
		{2041327411, 1631989620},
		{2078711279, 1634321820},
		{2104178931, 1638353220},
		{2120496865, 1636714020},
		{2123596685, 1636503180},
		{2138472342, 1637590800},
		{3318845111, 1618028800},
		{4317845111, 1620028800},
		{5162494923, 1652449800}, // 2022
		{5186883095, 1648764360},
		{5304951856, 1656718440},
		{5317829834, 1653152820},
		{5318092331, 1652024220},
		{5336336790, 1646368100},
		{5362593868, 1652024520},
		{5387234031, 1662137700},
		{5396587273, 1648014800},
		{5409444610, 1659025020},
		{5416026704, 1660925460},
		{5465223076, 1661710860},
		{5480654757, 1660926300},
		{5499934702, 1662130740},
		{5513192189, 1659626400},
		{5522237606, 1654167240},
		{5537251684, 1664269800},
		{5559167331, 1656718560},
		{5568348673, 1654642200},
		{5591759222, 1659025500},
		{5608562550, 1664012820},
		{5614111200, 1661780160},
		{5666819340, 1664112240},
		{5684254605, 1662134040},
		{5684689868, 1661304720},
		{5707112959, 1663803300},
		{5756095415, 1660925940},
		{5772670706, 1661539140},
		{5778063231, 1667477640},
		{5802242180, 1671821040},
		{5853442730, 1674866100}, // 2023
		{5859878513, 1673117760},
		{5885964106, 1671081840},
		{5982648124, 1686941700},
		{6020888206, 1675534800},
		{6032606998, 1686998640},
		{6057123350, 1676198350},
		{6058560984, 1686907980},
		{6101607245, 1686830760},
		{6108011341, 1681032060},
		{6132325730, 1692033840},
		{6182056052, 1687870740},
		{6279839148, 1688399160},
		{6306077724, 1692442920},
		{6321562426, 1688486760},
		{6364973680, 1696349340},
		{6386727079, 1691696880},
		{6429580803, 1692082680},
		{6527226055, 1690289160},
		{6813121418, 1698489600},
		{6865576492, 1699052400},
		{6925870357, 1701192327},
		{7000000000, 1711889200} // 2024
	};
	std::sort(userData.begin(), userData.end(), [](const UserData& a, const UserData& b) {
		return a.id < b.id;
		});
	for (size_t i = 1; i < userData.size(); ++i) {
		if (userId >= userData[i - 1].id && userId <= userData[i].id) {
			double t = static_cast<double>(userId - userData[i - 1].id) / (userData[i].id - userData[i - 1].id);

			return parseRegistrationTime("~ ", userData[i - 1].registrationTime + t *
				(userData[i].registrationTime - userData[i - 1].registrationTime));
		}
	}
	if (userId <= 1000000) {
		return parseRegistrationTime("< ", 1380326400);
	}
	else {
		return parseRegistrationTime("> ", 1711889200);
	}
}

rpl::producer<TextWithEntities> RegistrationValue(not_null<PeerData*> peer) {
	auto userId = peer->id.to<UserId>().bare;
	return rpl::single(findRegistrationTime(userId)) | Ui::Text::ToWithEntities();
}

// brazenly stole from ayugram