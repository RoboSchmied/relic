/*
 * RELIC is an Efficient LIbrary for Cryptography
 * Copyright (c) 2021 RELIC Authors
 *
 * This file is part of RELIC. RELIC is legal property of its developers,
 * whose names are not listed here. Please refer to the COPYRIGHT file
 * for contact information.
 *
 * RELIC is free software; you can redistribute it and/or modify it under the
 * terms of the version 2.1 (or later) of the GNU Lesser General Public License
 * as published by the Free Software Foundation; or version 2.0 of the Apache
 * License as published by the Apache Software Foundation. See the LICENSE files
 * for more details.
 *
 * RELIC is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the LICENSE files for more details.
 *
 * You should have received a copy of the GNU Lesser General Public or the
 * Apache License along with RELIC. If not, see <https://www.gnu.org/licenses/>
 * or <https://www.apache.org/licenses/>.
 */

/**
 * @file
 *
 * Implementation of configuration of prime elliptic curves over quartic
 * extensions.
 *
 * @ingroup epx
 */

#include "relic_core.h"

/*============================================================================*/
/* Private definitions                                                        */
/*============================================================================*/

/* See ep/relic_ep_param.c for discussion of MAP_U parameters. */

#if defined(EP_ENDOM) && FP_PRIME == 315
/** @{ */
#define B24_P315_A0		"0"
#define B24_P315_A1		"0"
#define B24_P315_A2		"0"
#define B24_P315_A3		"0"
#define B24_P315_B0		"0"
#define B24_P315_B1		"0"
#define B24_P315_B2		"0"
#define B24_P315_B3		"406CE9FD4AD2B7F7847659DC5909EE3951A263DEBF12A6EFCDF114294C8108BE8893D9CE78B13B2"
#define B24_P315_X0		"143A8108476CD513348A7BB62E823CC0D7F7E367CD75CA2AA6D9D9C4EE375F2204A6EC7171DFDF1"
#define B24_P315_X1		"152D57BA1ED90145569D652D68EBDB752986187DF157B360712A6ADBB2C1B19F9DFA929580FA921"
#define B24_P315_X2		"014E7F7DBA097CAD8A49E978757DE0755B7411812E0DCAA2AB2FC8D16531CFA2091753F07CC6726"
#define B24_P315_X3		"4074100502378B6D65F7C6603DDF2AC771E85417A709280468F91E1006A55B0A1D82B084997DB67"
#define B24_P315_Y0		"138582366AF8207D4E6B8E4D9BAF4CA15E08FCF676647F376FF4FE907627E2579D32AA8E6001DEE"
#define B24_P315_Y1		"0DEAD9C4C30BD897DF10EB443DEF49B5FA667FB8A84C90D1388AC58F993AFA6363D1BDA84CC1C1C"
#define B24_P315_Y2		"1615F1AA7F72E6C275654FD6389AE7382AED0DC06A49BF296317642D6C08A6BDB66EEA7EE76333A"
#define B24_P315_Y3		"36B589D9FE7C4A5F62F00C7B10A7EACB3CAB665DEDE5809BF77AC3313B08E7592D7D4D8C7AA5E18"
#define B24_P315_R		"196DEAC24A9DA12B25FC7EC9CF927A98C8C480ECE644E36419D0C5FD00C00001"
#define B24_P315_H		"142A76791A4ECF9C5E2D1E9744E1A3D20ECD4E893C629F9A3E8F21811C01446602B3EC97C88DB0069213228615137A0DDED7E599B628469C774CB87CD287BF73A8D2CC439FFFFE00FE2B41EFDC3698DD4B373ACDEEE183EB09E6F58E9055CD34EACE3E7E701215B52C02797E31A2C6FE9AC0018B940ADF101E0000000001"
/** @} */
#endif

#if defined(EP_ENDOM) && FP_PRIME == 317
/** @{ */
#define B24_P317_A0		"0"
#define B24_P317_A1		"0"
#define B24_P317_A2		"0"
#define B24_P317_A3		"0"
#define B24_P317_B0		"0"
#define B24_P317_B1		"0"
#define B24_P317_B2		"4"
#define B24_P317_B3		"0"
#define B24_P317_X0		"36A6220950C7870B9D42FF09CEFE0520DEAB97207021685B35BA445849CD469D1BE033F82E5F017"
#define B24_P317_X1		"C91F3B3134FB62C277EDDAF617551090B4CE7550B63A7DBDEC4AA7AA4398AC69460650EFC67408B"
#define B24_P317_X2		"1015C5600F61264941003D36E6C44373CFE660B3E58D022CD09022E888C30019F769BF66AA4D5B1D"
#define B24_P317_X3		"5BAD535DA2A42C5D074AF7C66E0A7F455343C891ADD40BE6FBBE7E3AA9AB0D43F72997D40039EA6"
#define B24_P317_Y0		"AF7E47B2C41683B76E545A9124E54500468CB736CF2511BFA4B2A701638DA87CF4DB32A05C28B24"
#define B24_P317_Y1		"19CA14178B54B1F00DFA9F1C2EE3EDAB9AAE97EC0D054B4442AC47F56C08F58E6461943B996D329"
#define B24_P317_Y2		"3CC71F2768CCABDB4E59ED5843672AAD9ED9CC9013FE03DC4385324FB2B89D19F8441EC780193F"
#define B24_P317_Y3		"101A83D160E4CAB745F944FE44506B4CA63098605B00D937EEBF4785587075D552E11033FF12E8F8"
#define B24_P317_R		"196DEAC24A9DA12B25FC7EC9CF927A98C8C480ECE644E36419D0C5FD00C00001"
#define B24_P317_H		"416447847BA373C0307445C51CE3F6794B6A196037B807603DEB0EA8A26CC88F0707D8CD9E96D7EA5C8E850F5306CC3B7285486A4F06BFE651956CC3CD1E6D77AE229D7DC65E3D9D309F43FAC42749B83735FDDD0560F1ECCA197EB86C2167E9522AE151DC5F2AC2703E82BB9F29F280E26EF9C0CFFD37140CE556FCCD6EB"
/** @} */
#endif

#if defined(EP_ENDOM) && FP_PRIME == 330
/** @{ */
#define K16_P330_A0		"0"
#define K16_P330_A1		"0"
#define K16_P330_A2		"1"
#define K16_P330_A3		"0"
#define K16_P330_B0		"0"
#define K16_P330_B1		"0"
#define K16_P330_B2		"0"
#define K16_P330_B3		"0"
#define K16_P330_X0		"0A8E1814295DCD3B32115B7ECA482E00E799D573C1C87226DF403C088C4E0D6867D0F782463D75EF703"
#define K16_P330_X1		"1C35DF89EBA1F4F7F0914CCC2217236A2DEBD627A4140DB7DE5B6C34B64CBFEB0D6A81D37175FC2D2D0"
#define K16_P330_X2		"121D8B058C749480DBD0C3B80A7A87A6062EAFBA48C38A4209D366182B5CF34144A63EA4D2D22A49810"
#define K16_P330_X3		"13DD1C6C7EF26A3BE18758FDD4DA5B1FC973B9C7B2FE6F95742E63209743DA5DC9D78508FFF7D6577F5"
#define K16_P330_Y0		"1D6E4D1204B71D526B26E4F9659A56950863CA7A11798AD0002A662C94925555508BDC74A72AFF20761"
#define K16_P330_Y1		"174D707AAB7BE8D7FD66A81C116C35FAA3DE173AF8E78EBF4D21946D1DAE273D2F01D18BF58FB6774F9"
#define K16_P330_Y2		"07B52F66D7F4F13D402C90F25289B984F4803D5AB4C5D27C38205B96A35D4BA7E21128C628CB8533252"
#define K16_P330_Y3		"230B103DC9594C0EAC2F136CAF4CC297EE32FBB5D6F2EB1F39F73ED0715410E528827C27A28E47E32C3"
#define K16_P330_R		"A9AE90F426EE7F9DB56D9C82F1C0B2CA3CB15B2F8ABF5803C963444D043D2731"
#define K16_P330_H		"29FFFB0947F8B82A090873C9E956B3A36AB6E037E0A77753117BF9F84FF2EB53D7B3AA3AFB0124167228D28EA26DF7AB6B4A69C60F0F66576B9A07331B9FB744EEF9DEB9AC59EF48BA9872139AF319E427E6DEEF4D6F24C1525725A22B36AA73476912FE2295DE6353A113DB8C14637D012DD09C2637D6F6EA569A3ABC835DF9E3AB55DA62"
/** @} */
#endif

#if defined(EP_ENDOM) && FP_PRIME == 509
/** @{ */
#define B24_P509_A0		"0"
#define B24_P509_A1		"0"
#define B24_P509_A2		"0"
#define B24_P509_A3		"0"
#define B24_P509_B0		"0"
#define B24_P509_B1		"0"
#define B24_P509_B2		"AAAAB7FFF9CE54DFE76F95A7CE0767B65C56424AE8C3F4619750081F008485DB13742DFBE0C507867E5AE3038DD69E97731DE83B746C980509E88C6DC5FE956"
#define B24_P509_B3		"AAAAB7FFF9CE54DFE76F95A7CE0767B65C56424AE8C3F4619750081F008485DB13742DFBE0C507867E5AE3038DD69E97731DE83B746C980509E88C6DC5FE955"
#define B24_P509_X0		"4D5AF70D2E605D1691DE7667FF1096AF4537749FD200277E1BC502847F63F4BC2F000FC81571F6E282FD46B96045CD611159ED554AFA95B2B1800A74F6A97C0"
#define B24_P509_X1		"EA0D1E6A2105587ED20E9CA255A777AC78D0A24AEB118B1CE4D1F213BE42F7FFD3F3F5F60F06F902FEE405DF84143D533006D7383C25A7F7C26656440A80A0B"
#define B24_P509_X2		"10E955FAFCA0C3C16D9DA9754859EAF918518C1A3FD0D14F427302CDE750224AD9E337CA12D3824B9E5E1668F94F56A4C2D935C6841C65FF4CA89E62C6A88D34"
#define B24_P509_X3		"A9A981033A3844468D815A18B921C9F7C2B152372F240EAC4848A942FEAA4019B086104AE4F86C929F5B9064B4FE917A327279CEDCE02962FD3E971F9D00CCA"
#define B24_P509_Y0		"C45C4179589584F8D1146550C117E3B452B7789170B7E7C0BEB1E417B5E32845CC1810760585AE0FE07762D94774A311932C100276C7A2EA4304EF7FBAA89F"
#define B24_P509_Y1		"20315B1CE6AEE44F7ADCAE2F0B178DF7574F91380DB5E4A27281D02CC47A24618F995ACC29E611D7BBCE63E8A2CBD783256A1799FFA2A5D061D6872962CBAD"
#define B24_P509_Y2		"20DEE7CA8DF5A616A014D78C0BCC69491116C715DDF5416C52B8A1833F8E4974255FBCCC5C6288DCA9B7CB2F4BB58525AB13D2225590A4A69955A859D36BF67"
#define B24_P509_Y3		"5CD7D6B0C7890DC487A34BE4976767DE0C20BEB43A0EE741A5ED21021EBE5BDC42281008E19C44497E13A38165A36019235BDF7A48E76B6BA79D527024D227C"
#define B24_P509_R		"100000FFFF870FF91CE195DB5B6F3EBD1E08C94C9E193B724ED58B907FF7C311A80D7CABC647746AE3ECB627C943998457FE001"
#define B24_P509_H		"32916E9E0188E2252DA44F42F6DC0E90A66E8C7AFA49D50688A07F362BA18A01F6D9317009D55DAF8CFA9159E35E2736DA6417B31C8550DFC6CD766340D92AB85D629676E78E12D5E76AB9FAC536661EEA6615242264E5F6B46EBA0F95191CD226B0CB144CEC686A846DE323CBE0244A3B6E5FFE49BD01599F13AD869FF3DA2E5551FD9C2D885EF8FB95EB7FFD5460EC84FA36A569BCB5BBBC5A21B025CECEEAD08540C0ACCB87D9136ECB9C2CEDC2D465831D76AC3551EE87BCA06B751C18699A1424FF71E791EB953FA79"
/** @} */
#endif

#if defined(EP_ENDOM) && FP_PRIME == 765
/** @{ */
#define FM16_P765_A0	"0"
#define FM16_P765_A1	"0"
#define FM16_P765_A2	"1"
#define FM16_P765_A3	"0"
#define FM16_P765_B0	"0"
#define FM16_P765_B1	"0"
#define FM16_P765_B2	"0"
#define FM16_P765_B3	"0"
#define FM16_P765_X0	"EA52AB67B443C778FDAD4A69F92C71AF91DFA14F1E9311F9931580427EA8AE3FB8FDBEA439156418AECEAF3779118AA3063FD5AE91CCAA71CB2A80142809E4329A79F14BD9EE4B544AE5DD4E165B7859E9A9E53FE20CC118A377FAC7EE03383"
#define FM16_P765_X1	"FF84E6B156239F35EE8CE26A50005A921F08ABE1188932030B8D967D4D4BB3141AA2740E0D47BE45DCC0A999FFAB378143100C8FB5EEA72123D9B6F4369AD068936ECE2819BF1CC377A76A26AD024FE8A5BA7D814E2C1B10194317FBE167A0"
#define FM16_P765_X2	"9D76B11D4F9C55C1FE9F26B63238C3FAF0910E728D3ADC4D7257F79125D273B85124D6BD0EAA25FBB4B7524F3D17F3879242A2CBECA4F46C90028E439CB95C506EEC3077612132F9168A865B0D8DF11B1F14BBF3DC8BF97F136A724B635F6AC"
#define FM16_P765_X3	"BC47D8993B5921DD0C1159BD25EF396A2FFCBDB7AE2F3CD9BA1C3F08BABEB4080F308F393B38EC9DAA97FFB076BE5A11CE4EAB250A803CC14E5E8C4240B3396E84461D4D18E97A7F958B1B62FC3F9B660993C8D26BAFB491BD654DBFEB9D0AD"
#define FM16_P765_Y0	"11AD3FC23DBE9ECF9683D753985679D485E3ADFF0EB31727F30C51034ED9CA51D1BBE4680B4A29802FA21867D4AFFA3183BD5A9F4537C9B54C08270D3FEC78A16F1B204344167D955B9B9D21620FEECD08A164B5E83A06F8364B9FE668DD6D16"
#define FM16_P765_Y1	"8679BA060D85D894CFF27F6535CC817058AC5F7B33D7A9EB131D5DD4C05B6E8205A1ED28928D930F5B4B020D5317873E257AFAAD153FE8CADDC751DA135F3CA0333F4A4CB43445A7B997E3352BB9F199B1FFFA9435993A166F31A3D81FD1E3C"
#define FM16_P765_Y2	"8E6C8D9A79BD0D7187D0D2C1285FB705138053984D865E1E5FDAB315D100AFEE4C403F592849ECD2146E8FED537E92BD606F3B856F4530D3F61E6F064F34580C19E6E9798C45C2FEC328C565649DDDC4E9E7EF6DC323CC3CC401AA27F817264"
#define FM16_P765_Y3	"E90F6A9653575AA7A158E8414F47C7CB777889FA45C550A76455C999C307B2F92DEFF4F129625FA4E3C2D0403EEB9D06F238862875E97B5DABDC51EAF5095DF38089EA8D165F767CF8E11C9DD34CE98B44A96BA1125ED81ABB137A822894FF6"
#define FM16_P765_R		"97806EA97185E5A71C9C881E055495FC0100000000000000000000000000000000000000000000000000000000000001"
#define FM16_P765_H		"6822EA3AA20627C198952D3A862F7922329CB37E53F890BF58E136C8578F4018ADB15BC58B2906276B272ED80976F28344FE7D36BE178B8A5589BE16EB483451CED64B6A44730FAA989051E1B87AC870364BCD14BE0893D560147CFFA3D313EE4A40AD71F8DA71980AD969768E3208C77240C6765CC9FEC7E67B23C3DEE0FC9B3FA681E45258CF2399008513635184F09CEB78E2D98FF766926C33D0CD33C59FDB1177ADFDB42CE45C73F65053289168A22A122C0DF279C7A10CC55B3CA63256BC71D953DC548E52B03790D30877280233B3D5FEC4E128CAAFDD23395D77E82F519F3D794D6BBD50A96BD483C9BA59537F39A1F892FAFD7C87426883477201546AA2D3774A597A2EB03DDB76B17C8AC8DBD425932DBC7FBAD3E701C7E8BC6488EC12F0A3756D5D3A3EFB06BD20ABDE389CAC64A7E7CCB9CB1EB996E6F75F1367D92B703BEFE41C003BF0200000002"
/** @} */
#endif

#if defined(EP_ENDOM) && FP_PRIME == 766
/** @{ */
#define K16_P766_A0		"0"
#define K16_P766_A1		"0"
#define K16_P766_A2		"1"
#define K16_P766_A3		"0"
#define K16_P766_B0		"0"
#define K16_P766_B1		"0"
#define K16_P766_B2		"0"
#define K16_P766_B3		"0"
#define K16_P766_X0		"2864F5E5FB6FED078FAD04D5587701E9973407697AB1BBF402111C686E6FD2AFD20658BB74DCE094C1316032413E662255F923A11D68AB9851527074A01855830F521B431F14026FCB0BD075402203D31C4DA096A9B85EC3B297144700D2D377"
#define K16_P766_X1		"2823AC7365F9C56A3B5C27882F05C971087A0D54E44AA1C4D697C1BF371E7DA060FC680601C3F78AA6D8BD91BDCD213ACA6D65A3700742900FB4D3A3AA78C2EBD61763CD4727C057BF9EEA3A5EACC023B66B61A3473BE5BCF98125A91F1C084E"
#define K16_P766_X2		"37FC8358DC23B2A6FE3763ED787841E4355D203DD94A113A6EFEF3ED4E4ED1D7D47E5B7B8F85CF52C0B2479ECC74AAB21C56537D80708D65C1BC1E5E6FF69CC93B2F292DA61270386520FB79B780DE7BEF87EF43006EADCDF3AF82ED9556A0A4"
#define K16_P766_X3		"2E699CE6FA1448A9523F867F0C1FCB9C4CE22B007C058C474EF0BAEA2B3E3F486BC1A6A3BF0C396D23E60C60C7FBCDFF8AFF535E9786923B3E8798E23724355422DA4E3AB07D9FF519C94A79610CBF0449A4FC8AB1EEB75EC87879F22655F850"
#define K16_P766_Y0		"03F2F35FCFCCEA92B77B4C6F7A331D1EF96E9616CB26539FF018D0DE51B2A536CE69C9E564B665A6C806CE46AF3DD7FA478AB78548526E0305545C332A5DD7A19694069C2D9585197ED80C81BF9F2CBDD7A0F0FE37156FACF93D2FCC4F2241D5"
#define K16_P766_Y1		"02F05261C24AC6F7948C6F86E458E011E71E619BE8C8119E438EE184979A5F64D07A3845A7189FB1B9D0BC90E625C7194C43EA281559DD09A2E2FCE5A7D1CC50E8176F5458A620C70DCD32F1FEAB870D7B9AEC8F9620B9D88BA201C59511228D"
#define K16_P766_Y2		"12936CF6E9B0279986ABD00C068B7376CA39D4EEAF2598D4276DC1060D75069A8E11E61C526BEDF38E523B9C176E34EF193B958B818CEF1FEE3FCB092D903EA747CB08F9B98338CE500030BE5539EDA6FBEE2B47A60EF989E180B50E125565BF"
#define K16_P766_Y3		"16CBBA489FA40077403ECBE1817781E753BEBA8507D44A7FB6D40737E84C754ECA100C336243F9E763D8D71D31117EACDAB48C59E55065CEABAE97EC2CC66E0878F2377CF8E9312FF6615661D909314C28D5173B725BB81DF63465D862BBD53D"
#define K16_P766_R		"1B6C1BFC8E56CCE359E1D8A9B94553D096A506CE2ECF4A33C5D526AC5F3B61CB0A6D76FCD8487EDEE0B0F9BA2DFA29D5AB0B164B8792C233ED1E6EB350BA9F4D37112A98DE816BEB1EA8DDB1"
#define K16_P766_H		"755986B96E4AAB1797EAEDDCB714FA0EC4E13C9AF468746FEE467D8D27293EF56C4CFA83CC6DD8774B03009353D93F100EC1314BAB5764E3D32F3DA621C7B3DDACB086098C31F7999CA8F4EA67165C3595BFAD8DBE5B7951091040E97CC5A27149F16A9A960F2557EC038032C876E49E4C40E56C1BD543BD910CB3BAABFA2F9179D2B1711E168A6472FCC1A8D8AF3415559DBF3108029DB68CC8343D397F78577E9EF7DFE8E239D9F5D9EBC1011B8F9E6043DD53C1B98C12BFA48E8A17B3BB0F5DE92DEEA7C9088EA9A643C66D4016BF81616AE20C609045A3EBA6AF3F7BEDC6AE78ABBF788F36CA894B789C84C484B4D31B83DB5CC95783DA34FC601EF7D7F07F60128E0F0E007AE29AB2F98C7A483F0E4CA614E4E45650D3E210A2EB030A6C339DB66CC198FE0EAC1CA827A8A975D094B7862"
/** @} */
#endif

#if defined(EP_ENDOM) && FP_PRIME == 766
/** @{ */
#define N16_P766_A0		"0"
#define N16_P766_A1		"0"
#define N16_P766_A2		"1"
#define N16_P766_A3		"0"
#define N16_P766_B0		"0"
#define N16_P766_B1		"0"
#define N16_P766_B2		"0"
#define N16_P766_B3		"0"
#define N16_P766_X0		"36097A5BDF2276730FCAC23EA21B0C85D46B013D5A33B2D403BD82155F681BC3A1213F7AD40BFD5B64409C6B909A44F1AC391DE4222B56C55CC74DCB5DCEC23696575F80C402A1256C267F9D1CA325558C3357B116AC85CF856E51590FE7C34F"
#define N16_P766_X1		"17CC3006229289EEC6AAA00FD81F17F26CECDE216E03B5DF64B61FEBA6DFF9D3F032642D66F8E5D4DE44934FB1CB99AFB0A6A939ADAFDA1E6197A474C3BBDDBA71E6120B3AAFE1007A8D0F360651B316312F902B1EB346DD2B276FEEE75ABDD1"
#define N16_P766_X2		"2B79EC9BDF7F80A86DD7F3CE18A3D1FAAEAEDE9312797735EA7F090760B4730CEE401EF9CAB0978C14E967FCE1CEEF5660DFA40F367F698D0CDE9C0F0EF361D70E186EA991CD0F6DB63FE88C45EC5909DFC866862C7B1D1DE6A04843761E5E3"
#define N16_P766_X3		"2005908CF374B24B1C7CF8C5CE656D04515082E61F3088C28D58B9E0249CA864AF1773F479D3272C567311FB287E579547743E8CA51A9D4B45FF5D3D6B4A2BB1865B6E4FB045953D716C68A73095A74CCDDAD5AFCEA74E676D37452916B5CB24"
#define N16_P766_Y0		"137A898DDF4399F2ABB29920707790495F645B373F419C4E2A96DA05B90488BED334F2B8A44AF71C92D947009618358A14F8DE18F0D777F0DE4F98625C4024DBEB8EA858A7AEFAEC093EA12ED7A7C70142AE3583D27982B26AFD75FB441A4B66"
#define N16_P766_Y1		"4D0ADEC5B4B77DFBEB78227FC664F7520A469DBEA674C845F64B537ABFB808F9857EEFBDE088D0422C919ECD562D7C668A42F6C2DAB0B26D7C4D4C3B835CBEA2A843CD3A449B44F0D6D4026512670C3600B02CEFDF9BBF21975B596DD732C13"
#define N16_P766_Y2		"2FCE7D8564D037E95317C3110542BB780D8824436B6F3626C8A4BF1D1C1FB7C1FDF12E7BC52D9F19914404EF71873EFB36C95AF0C6635329D556431A902BA01186D968C0D4BF55F17F7FED3072D77D9DE8D151135952C6EE7855E8F6176B4D66"
#define N16_P766_Y3		"2BAD268ACF32E9D617EC80588A3F1063C5565008B9DF82E8E9B8451F874C36157A280057EF467E0BFCA1FE7AF5C79CDCD055011B2F0F14764B8F1C97BEA256BD5A40FC8020486507E52413A11B70F8D6A3ACF396D5F0D8902950A3E3821B4C64"
#define N16_P766_R		"FFFF7000238FFAF4807374994CF93FE6E28D406881B18D350193FE6E3E533E4073749FEBD2000238FFFFDC0000010001"
#define N16_P766_H		"FFFC10079DE659DE808DDCE130F752738172840B38A5FC5FC7E040BFD9DCEE27BC5A7B95CED5C4229B3FA11F8F6FAE01BE1FBBBAF34CEF81E7CAFC72FAA4ECB8710AB4E1097D5F96BC6E8A5A88DE77C8B1F025B2691EEE839B4DBE2AC3433AA9E3567E22C5F26F401F6D0458C5F931050EB64B76A27B1D74E69AF8751AB329F9AA6F80C46E4F46D6727D476002C6DD1893DDC185AE4BE7842818B8DF91045FAF7F0A85549CFF3D6F3F45C0010E9F70243663C0840EEE489118422163CFDA9A843ABA6C408D3EC6C858FEDF4BDE93A28C7FD16B34CC1E1074ADB78D9F4F7F5E96DC4F0C5DCA4F360BCB4933A50ABAC5204B89055875059167BA03E0402A1CB965B48313B481483B26F3F1192C673BC76FBDA8395741062530251758B6B86500570F6C3FAF490A5C01D1B62653C6C1DF188A9358877DC50DAB36655B01F092A8AF90F6259FB91E5D57E2DA8FDD5F06A2"
/** @} */
#endif

/**
 * Assigns a set of ordinary elliptic curve parameters.
 *
 * @param[in] CURVE		- the curve parameters to assign.
 */
#define ASSIGN(CURVE)														\
	RLC_GET(str, CURVE##_A0, sizeof(CURVE##_A0));							\
	fp_read_str(a[0][0], str, strlen(str), 16);								\
	RLC_GET(str, CURVE##_A1, sizeof(CURVE##_A1));							\
	fp_read_str(a[0][1], str, strlen(str), 16);								\
	RLC_GET(str, CURVE##_A2, sizeof(CURVE##_A2));							\
	fp_read_str(a[1][0], str, strlen(str), 16);								\
	RLC_GET(str, CURVE##_A3, sizeof(CURVE##_A3));							\
	fp_read_str(a[1][1], str, strlen(str), 16);								\
	RLC_GET(str, CURVE##_B0, sizeof(CURVE##_B0));							\
	fp_read_str(b[0][0], str, strlen(str), 16);								\
	RLC_GET(str, CURVE##_B1, sizeof(CURVE##_B1));							\
	fp_read_str(b[0][1], str, strlen(str), 16);								\
	RLC_GET(str, CURVE##_B2, sizeof(CURVE##_B2));							\
	fp_read_str(b[1][0], str, strlen(str), 16);								\
	RLC_GET(str, CURVE##_B3, sizeof(CURVE##_B3));							\
	fp_read_str(b[1][1], str, strlen(str), 16);								\
	RLC_GET(str, CURVE##_X0, sizeof(CURVE##_X0));							\
	fp_read_str(g->x[0][0], str, strlen(str), 16);							\
	RLC_GET(str, CURVE##_X1, sizeof(CURVE##_X1));							\
	fp_read_str(g->x[0][1], str, strlen(str), 16);							\
	RLC_GET(str, CURVE##_X2, sizeof(CURVE##_X2));							\
	fp_read_str(g->x[1][0], str, strlen(str), 16);							\
	RLC_GET(str, CURVE##_X3, sizeof(CURVE##_X3));							\
	fp_read_str(g->x[1][1], str, strlen(str), 16);							\
	RLC_GET(str, CURVE##_Y0, sizeof(CURVE##_Y0));							\
	fp_read_str(g->y[0][0], str, strlen(str), 16);							\
	RLC_GET(str, CURVE##_Y1, sizeof(CURVE##_Y1));							\
	fp_read_str(g->y[0][1], str, strlen(str), 16);							\
	RLC_GET(str, CURVE##_Y2, sizeof(CURVE##_Y2));							\
	fp_read_str(g->y[1][0], str, strlen(str), 16);							\
	RLC_GET(str, CURVE##_Y3, sizeof(CURVE##_Y3));							\
	fp_read_str(g->y[1][1], str, strlen(str), 16);							\
	RLC_GET(str, CURVE##_R, sizeof(CURVE##_R));								\
	bn_read_str(r, str, strlen(str), 16);									\
	RLC_GET(str, CURVE##_H, sizeof(CURVE##_H));								\
	bn_read_str(h, str, strlen(str), 16);									\

/**
 * Detects an optimization based on the curve coefficients.
 */
static void detect_opt(int *opt, fp4_t a) {
	fp4_t t;
	fp4_null(t);

	RLC_TRY {
		fp4_new(t);
		fp4_set_dig(t, 3);
		fp4_neg(t, t);

		if (fp4_cmp(a, t) == RLC_EQ) {
			*opt = RLC_MIN3;
		} else if (fp4_is_zero(a)) {
			*opt = RLC_ZERO;
		} else if (fp4_cmp_dig(a, 1) == RLC_EQ) {
			*opt = RLC_ONE;
		} else if (fp4_cmp_dig(a, 2) == RLC_EQ) {
			*opt = RLC_TWO;
		} else if ((fp_bits(a[0][0]) <= RLC_DIG) && fp_is_zero(a[0][1]) &&
				fp2_is_zero(a[1])) {
			*opt = RLC_TINY;
		} else {
			*opt = RLC_HUGE;
		}
	}
	RLC_CATCH_ANY {
		RLC_THROW(ERR_CAUGHT);
	}
	RLC_FINALLY {
		fp4_free(t);
	}
}

/*============================================================================*/
/* Public definitions                                                         */
/*============================================================================*/

void ep4_curve_init(void) {
	ctx_t *ctx = core_get();

#ifdef EP_PRECO
	for (int i = 0; i < RLC_EP_TABLE; i++) {
		ctx->ep4_ptr[i] = &(ctx->ep4_pre[i]);
	}
#endif

#if ALLOC == DYNAMIC
	ep4_new(ctx->ep4_g);
	fp4_new(ctx->ep4_a);
	fp4_new(ctx->ep4_b);
#endif

#ifdef EP_PRECO
#if ALLOC == DYNAMIC
	for (int i = 0; i < RLC_EP_TABLE; i++) {
		fp4_new(ctx->ep4_pre[i].x);
		fp4_new(ctx->ep4_pre[i].y);
		fp4_new(ctx->ep4_pre[i].z);
	}
#endif
#endif
	bn_make(&(ctx->ep4_r), RLC_FP_DIGS);
	bn_make(&(ctx->ep4_h), RLC_FP_DIGS);
}

void ep4_curve_clean(void) {
	ctx_t *ctx = core_get();
	if (ctx != NULL) {
#ifdef EP_PRECO
		for (int i = 0; i < RLC_EP_TABLE; i++) {
			fp4_free(ctx->ep4_pre[i].x);
			fp4_free(ctx->ep4_pre[i].y);
			fp4_free(ctx->ep4_pre[i].z);
		}
#endif
		bn_clean(&(ctx->ep4_r));
		bn_clean(&(ctx->ep4_h));
		ep4_free(ctx->ep4_g);
		fp4_free(ctx->ep4_a);
		fp4_free(ctx->ep4_b);
	}
}

int ep4_curve_opt_a(void) {
	return core_get()->ep4_opt_a;
}

int ep4_curve_opt_b(void) {
	return core_get()->ep4_opt_b;
}

int ep4_curve_is_twist(void) {
	return core_get()->ep4_is_twist;
}

void ep4_curve_get_gen(ep4_t g) {
	ep4_copy(g, core_get()->ep4_g);
}

void ep4_curve_get_a(fp4_t a) {
	fp4_copy(a, core_get()->ep4_a);
}

void ep4_curve_get_b(fp4_t b) {
	fp4_copy(b, core_get()->ep4_b);
}

void ep4_curve_get_ord(bn_t n) {
	ctx_t *ctx = core_get();
	if (ctx->ep4_is_twist) {
		ep_curve_get_ord(n);
	} else {
		bn_copy(n, &(ctx->ep4_r));
	}
}

void ep4_curve_get_cof(bn_t h) {
	bn_copy(h, &(core_get()->ep4_h));
}

#if defined(EP_PRECO)

ep4_t *ep4_curve_get_tab(void) {
#if ALLOC == AUTO
	return (ep4_t *)*(core_get()->ep4_ptr);
#else
	return core_get()->ep4_ptr;
#endif
}

#endif

void ep4_curve_set_twist(int type) {
	char str[8 * RLC_FP_BYTES + 1];
	ctx_t *ctx = core_get();
	ep4_t g;
	fp4_t a, b;
	bn_t r, h;

	ep4_null(g);
	fp4_null(a);
	fp4_null(b);
	bn_null(r);
	bn_null(h);

	ctx->ep4_is_twist = 0;
	if (type == RLC_EP_MTYPE || type == RLC_EP_DTYPE) {
		ctx->ep4_is_twist = type;
	} else {
		return;
	}

	RLC_TRY {
		ep4_new(g);
		fp4_new(a);
		fp4_new(b);
		bn_new(r);
		bn_new(h);

		switch (ep_param_get()) {
#if FP_PRIME == 315
			case B24_P315:
				ASSIGN(B24_P315);
				break;
#elif FP_PRIME == 317
			case B24_P317:
				ASSIGN(B24_P317);
				break;
#elif FP_PRIME == 330
			case K16_P330:
				ASSIGN(K16_P330);
				break;
#elif FP_PRIME == 509
			case B24_P509:
				ASSIGN(B24_P509);
				break;
#elif FP_PRIME == 765
			case FM16_P765:
				ASSIGN(FM16_P765);
				break;
#elif FP_PRIME == 766
			case K16_P766:
				ASSIGN(K16_P766);
				break;
			case N16_P766:
				ASSIGN(N16_P766);
				break;
#endif
			default:
				(void)str;
				RLC_THROW(ERR_NO_VALID);
				break;
		}

		fp4_zero(g->z);
		fp4_set_dig(g->z, 1);
		g->coord = BASIC;

		ep4_copy(ctx->ep4_g, g);
		fp4_copy(ctx->ep4_a, a);
		fp4_copy(ctx->ep4_b, b);

		detect_opt(&(ctx->ep4_opt_a), ctx->ep4_a);
		detect_opt(&(ctx->ep4_opt_b), ctx->ep4_b);

		bn_copy(&(ctx->ep4_r), r);
		bn_copy(&(ctx->ep4_h), h);

		if (ep4_curve_opt_b() == RLC_ZERO) {
			fp2_zero(a[0]);
			fp_copy(a[1][0], ctx->fp2_p2[1][0]);
			fp_copy(a[1][1], ctx->fp2_p2[1][1]);
			fp4_inv(a, a);
			fp_copy(ctx->fp4_p1[0], a[1][0]);
			fp_copy(ctx->fp4_p1[1], a[1][1]);
			if (fp2_is_zero(a[1])) {
				ctx->frb4 = 0;
			} else {
				ctx->frb4 = 1;
			}
		} else {
			if (type == RLC_EP_MTYPE) {
				fp2_zero(a[0]);
				fp_copy(a[1][0], ctx->fp4_p1[0]);
				fp_copy(a[1][1], ctx->fp4_p1[1]);
				fp4_inv(a, a);
				fp_copy(ctx->fp4_p1[0], a[1][0]);
				fp_copy(ctx->fp4_p1[1], a[1][1]);
			}
		}

#if defined(WITH_PC)
		/* Compute pairing generator. */
		pc_core_calc();
#endif

#if defined(EP_PRECO)
		ep4_mul_pre((ep4_t *)ep4_curve_get_tab(), ctx->ep4_g);
#endif
	}
	RLC_CATCH_ANY {
		RLC_THROW(ERR_CAUGHT);
	}
	RLC_FINALLY {
		ep4_free(g);
		fp4_free(a);
		fp4_free(b);
		bn_free(r);
		bn_free(h);
	}
}

void ep4_curve_set(const fp4_t a, const fp4_t b, const ep4_t g, const bn_t r, const bn_t h) {
	ctx_t *ctx = core_get();
	ctx->ep4_is_twist = 0;

	fp4_copy(ctx->ep4_a, a);
	fp4_copy(ctx->ep4_b, b);

	ep4_norm(ctx->ep4_g, g);
	bn_copy(&(ctx->ep4_r), r);
	bn_copy(&(ctx->ep4_h), h);

#if defined(EP_PRECO)
	ep4_mul_pre((ep4_t *)ep4_curve_get_tab(), ctx->ep4_g);
#endif
}
