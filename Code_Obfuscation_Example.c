// BEFORE CODE OBFUSCATION.

modded class MissionServer {
    void MissionServer() {
        Print("Global Chat Initing..");

        GetRPCManager().AddRPC("RPC_GlobalChatAddon", "SendChatToPlayers", this, SingleplayerExecutionType.Server);
        GetRPCManager().AddRPC("RPC_GlobalChatAddon", "GetPlayersList", this, SingleplayerExecutionType.Server);

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.BroadCastPlayerList, 10000, true);

        GetGlobalChatAddonServerManager();
    }

    void SendChatToPlayers(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) {
        if (type == CallType.Server) {
            Param1 < ref GlobalChatMessage > data;
            ctx.Read(data);

            GlobalChatMessage message = data.param1;

            message.SetSteamUID(sender.GetPlainId());
            string playerID = message.GetSteamUID();

            if (GlobalChatAddonServerManager.IsMuted(playerID)) {
                ref GlobalChatMessage warning = new GlobalChatMessage(NULL, "Server mute", new GlobalChatARGB(255, 255, 0, 0));
                warning.SetPlayerName("SERVER");

                GetRPCManager().SendRPC("RPC_GlobalChatAddon", "OnGlobalChatBroadcasted", new Param1 < ref GlobalChatMessage > (warning), true, sender);

                return;
            }
            TStringArray naughtywords = {
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word",
                "Bad Word"
            };
            string messageStr = message.GetMessage();
            string messageLower = messageStr + "";
            messageLower.ToLower();

            foreach(string naughtyword: naughtywords) {
                naughtyword.ToLower();
                int index = messageLower.IndexOf(naughtyword);

                TStringArray wordsInMessage = new TStringArray;
                messageLower.Split(" ", wordsInMessage);

                foreach(string word: wordsInMessage) {
                    if (word == naughtyword) {
                        GlobalChatAddonServerManager.MutePlayer(new GlobalChatPlayer(sender.GetName(), sender.GetPlainId(), sender.GetId()));
                        ref GlobalChatMessage badwordmute = new GlobalChatMessage(NULL, "Server mute.", new GlobalChatARGB(255, 255, 0, 0));
                        badwordmute.SetPlayerName("SERVER");

                        GetRPCManager().SendRPC("RPC_GlobalChatAddon", "OnGlobalChatBroadcasted", new Param1 < ref GlobalChatMessage > (badwordmute), true, sender);
                        return;
                    }
                }

                if (index != -1) {
                    if ((index >= 0 && IsLetter(messageLower.Substring(index - 1, 1))) || (index + naughtyword.Length() < messageLower.Length() && IsLetter(messageLower.Substring(index + naughtyword.Length(), 1))))
                        continue;

                    GlobalChatAddonServerManager.MutePlayer(new GlobalChatPlayer(sender.GetName(), sender.GetPlainId(), sender.GetId()));
                    ref GlobalChatMessage anotherbadwordmute = new GlobalChatMessage(NULL, "Server mute.", new GlobalChatARGB(255, 255, 0, 0));
                    anotherbadwordmute.SetPlayerName("SERVER");

                    GetRPCManager().SendRPC("RPC_GlobalChatAddon", "OnGlobalChatBroadcasted", new Param1 < ref GlobalChatMessage > (anotherbadwordmute), true, sender);

                    return;
                }
                while (index != -1) {
                    int wordEnd = index + naughtyword.Length();
                    for (int i = 0; i < naughtyword.Length(); i++) {
                        messageStr[index + i] = "*";
                    }
                    index = messageLower.IndexOfFrom(wordEnd, naughtyword);
                }
            }

            message.SetColor(GlobalChatAddonServerManager.GetTierColor(playerID));
            message.SetRole(GlobalChatAddonServerManager.GetRole(playerID));

            GetRPCManager().SendRPC("RPC_GlobalChatAddon", "OnGlobalChatBroadcasted", new Param1 < ref GlobalChatMessage > (message));
        }
    }

    bool IsLetter(string str) {
        string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        return letters.IndexOf(str) >= 0;
    }

    void GetPlayersList(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) {
        if (type == CallType.Server) {

            BroadCastPlayerList(sender);
        }
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
        super.InvokeOnConnect(player, identity);

        BroadCastPlayerList();
    }

    void BroadCastPlayerList(ref PlayerIdentity sender = NULL) {

        ref array < Man > mans = new array < Man > ;
        GetGame().GetPlayers(mans);

        ref array < ref GlobalChatPlayer > globalChatPlayers = new array < ref GlobalChatPlayer > ();

        foreach(Man man: mans) {
            PlayerBase player = PlayerBase.Cast(man);

            if (!player)
                continue;

            globalChatPlayers.Insert(new GlobalChatPlayer(player.GetIdentity().GetName(), player.GetIdentity().GetPlainId(), player.GetIdentity().GetId()));

        }

        if (sender)
            GetRPCManager().SendRPC("RPC_GlobalChatAddon", "HandlePlayersList", new Param1 < array < ref GlobalChatPlayer >> (globalChatPlayers), true, sender);
        else
            GetRPCManager().SendRPC("RPC_GlobalChatAddon", "HandlePlayersList", new Param1 < array < ref GlobalChatPlayer >> (globalChatPlayers), true);
    }
}


========================================================================================================================================================================================================================================
========================================================================================================================================================================================================================================

/*
* This script was obfuscated using PBO Tools - Professional Edition
* Purchase your copy at https://pbo.tools
*/
modded class MissionServer {
XwqDJvrmXw47s97 MissionServer() {
Print(kikAjVIj("79748091BA6F0C9851785D3A2DBF51C2835C83888A", ("sUc1EVYoU6RDLf".Hash() + __LINE__.ToInt())));
GetRPCManager().AddRPC(kikAjVIj("66904C96595391B4417C6C6B6454939C8B9B50", ("bwhy1I1uWmdMhy".Hash() + __LINE__.ToInt())), kikAjVIj("A659CBB5664F57D246CA42506488BF6666", ("VS6Pt1HtVAsJ32".Hash() + __LINE__.ToInt())), this, SingleplayerExecutionType.Server);
GetRPCManager().AddRPC(kikAjVIj("897E36613F89635792BD3E6C84CC8A7CC0C190", ("lbUZqUqdZ3GsVv".Hash() + __LINE__.ToInt())), kikAjVIj("2E5BC36C87899E4C68864E8457A3", ("QTNvVbm6agILR7".Hash() + __LINE__.ToInt())), this, SingleplayerExecutionType.Server);
GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.BroadCastPlayerList, 10000, true);
vWTapnaCoPQG();
}
XwqDJvrmXw47s97 vJAmOvoViVFM(ZtrUPfBzRFKQHHq type, ref OYmakunmewNrsKo ctx, ref vvO9t6rTCeSN1gv sender, ref hMIsyqIQckN9ExE target) {
if (type == CallType.Server) {
MW6B2fJp2e5yoeg < ref rwSfHNwZ > data;
ctx.Read(data);
rwSfHNwZ WNcEUoYj = data.param1;
WNcEUoYj.TuoQXLMtX(sender.GetPlainId());
JS2JumdfaA6c1zr KkcNTOHO = WNcEUoYj.GetSteamUID();
if (mgXTFwgN.yzmwiIqbkJfp(KkcNTOHO)) {
ref rwSfHNwZ mfWRicHX = new rwSfHNwZ(NULL, kikAjVIj("5154CBA28C56076D8E7351890C5B8E62C4B1A10941638071926883A9A242B6BFADCD9057B080BD48706357", ("icCRwXthEoKYC8".Hash() + __LINE__.ToInt())), new GlobalChatARGB(255, 255, 0, 0));
mfWRicHX.SetPlayerName(kikAjVIj("78A3377E95B0", ("GGUpK89QabHZGX".Hash() + __LINE__.ToInt())));
GetRPCManager().SendRPC(kikAjVIj("A15652683EC2B07D5FA86F9248CB9FAE7B668A", ("RBgZkCjmAK06wk".Hash() + __LINE__.ToInt())), kikAjVIj("3362888976B88B962E4951B35CACAA53AD71BDCA9AC3B1", ("A8CCAUzAQOnTpt".Hash() + __LINE__.ToInt())), new MW6B2fJp2e5yoeg < ref rwSfHNwZ > (mfWRicHX), true, sender);
return;
}
GSNIEZG0r9jyb42 DdNslNEJ = {
kikAjVIj("625285A6B86B", ("4eJB6pQV1Pms0D".Hash() + __LINE__.ToInt())),
kikAjVIj("5E528D6F", ("7Pz7zmmVkXO3ub".Hash() + __LINE__.ToInt())),
kikAjVIj("6FA48C80C084", ("N33LtFNinVQFJ0".Hash() + __LINE__.ToInt())),
kikAjVIj("4E35A783A385", ("2jCADH7z1FVRCE".Hash() + __LINE__.ToInt())),
kikAjVIj("8B8FA3AF2AB3", ("lnKHbtNnXn36Sv".Hash() + __LINE__.ToInt())),
kikAjVIj("B68356857A96", ("qV9Zdskak7hpFX".Hash() + __LINE__.ToInt())),
kikAjVIj("7455519A", ("CmEyll8mRD2k2g".Hash() + __LINE__.ToInt())),
kikAjVIj("8E8F63B3825D", ("HPyzmLKGBe9N8o".Hash() + __LINE__.ToInt())),
kikAjVIj("5AA24C", ("jFLtZjAvjsVYNN".Hash() + __LINE__.ToInt())),
kikAjVIj("79B98E", ("sh0BVvdhfSbzQW".Hash() + __LINE__.ToInt())),
kikAjVIj("7572C06DBC", ("lDj0FJk8NODBwe".Hash() + __LINE__.ToInt())),
kikAjVIj("8F5C9982CCCB", ("HCcMmHOTCQF7yq".Hash() + __LINE__.ToInt())),
kikAjVIj("B0797797AA", ("DVLwoMT4unouEL".Hash() + __LINE__.ToInt())),
kikAjVIj("AF936B8D6F", ("wHZuCXhTfJihWV".Hash() + __LINE__.ToInt())),
kikAjVIj("A03DBB0F6E3A680659", ("WHUAlpIiWSGGj7".Hash() + __LINE__.ToInt())),
kikAjVIj("6D665A4273", ("INKGB21g4SN5sE".Hash() + __LINE__.ToInt())),
kikAjVIj("5650B88063", ("Vu9FAA0ZRtc0o7".Hash() + __LINE__.ToInt())),
kikAjVIj("BC8D9B6F54C1", ("aIbOY9xdDUkZxC".Hash() + __LINE__.ToInt())),
kikAjVIj("749779535668", ("bO88nsdERbCDV9".Hash() + __LINE__.ToInt())),
kikAjVIj("772CAD7CB94BAE42467180", ("CECtkOYijNcUpL".Hash() + __LINE__.ToInt())),
kikAjVIj("8E6360BD", ("K0BJbauTYSKOLJ".Hash() + __LINE__.ToInt())),
kikAjVIj("5A76A39D537A66", ("QGL025GK1TIyZC".Hash() + __LINE__.ToInt())),
kikAjVIj("8456C2", ("qhgPq2be2LjXjZ".Hash() + __LINE__.ToInt())),
kikAjVIj("4D1775009D085971996466", ("MTYfTbPpN8vwkY".Hash() + __LINE__.ToInt())),
kikAjVIj("B75B5FB2859391", ("tOBoS2n749CQAx".Hash() + __LINE__.ToInt()))
};
JS2JumdfaA6c1zr RSRwLAXQ = WNcEUoYj.GetMessage();
JS2JumdfaA6c1zr IqduHQpx = RSRwLAXQ + "";
IqduHQpx.ToLower();
foreach(JS2JumdfaA6c1zr PQCbfvYB: DdNslNEJ) {
PQCbfvYB.ToLower();
rQe8nePTKR9aOZn DIMPUFKw = IqduHQpx.IndexOf(PQCbfvYB);
GSNIEZG0r9jyb42 oAmOkixN = new GSNIEZG0r9jyb42;
IqduHQpx.Split(kikAjVIj("6C", ("38tGaxGlQe7mp2".Hash() + __LINE__.ToInt())), oAmOkixN);
foreach(JS2JumdfaA6c1zr uMggrOwcj: oAmOkixN) {
if (uMggrOwcj == PQCbfvYB) {
mgXTFwgN.ZDPzZIHUHhtg(new GlobalChatPlayer(sender.GetName(), sender.GetPlainId(), sender.GetId()));
ref rwSfHNwZ CNJbbsHyI = new rwSfHNwZ(NULL, kikAjVIj("96C27AC1B45E727A74D28D31368293914B49AD1E66597F8E696CB0D09486BB8EC5D1A9AAA5ABB7276D7591", ("ZNuJxWNhF7MGjV".Hash() + __LINE__.ToInt())), new GlobalChatARGB(255, 255, 0, 0));
CNJbbsHyI.pJDGAMrLF(kikAjVIj("999FA5996CA8", ("yqTxHxiM3iw4EL".Hash() + __LINE__.ToInt())));
GetRPCManager().SendRPC(kikAjVIj("7D8D84483EBDAE7E4FAA4A5C7FBB399459C580", ("7TD82cR2wrK4H8".Hash() + __LINE__.ToInt())), kikAjVIj("995C44C484BCBCA77C83AC84779370B5944477A7999976", ("upbpHlKTmvzi4U".Hash() + __LINE__.ToInt())), new MW6B2fJp2e5yoeg < ref rwSfHNwZ > (CNJbbsHyI), true, sender);
return;
}
}
if (DIMPUFKw != -1) {
if ((DIMPUFKw >= 0 && aVkqAcWuWyxZ(IqduHQpx.Substring(DIMPUFKw - 1, 1))) || (DIMPUFKw + PQCbfvYB.Length() < IqduHQpx.Length() && aVkqAcWuWyxZ(IqduHQpx.Substring(DIMPUFKw + PQCbfvYB.Length(), 1))))
continue;
mgXTFwgN.ZDPzZIHUHhtg(new iULXOCxCummq(sender.GetName(), sender.GetPlainId(), sender.GetId()));
ref rwSfHNwZ UnGIHljbrnTI = new rwSfHNwZ(NULL, kikAjVIj("519697747F545C92CF85AB28263DAD9E57657803441763B86C48B3AB7B747D5FC0D35DA865998077B0775F", ("8O4JFjjhW16ya7".Hash() + __LINE__.ToInt())), new GlobalChatARGB(255, 255, 0, 0));
UnGIHljbrnTI.pJDGAMrLF(kikAjVIj("9F343CAF4F62", ("Tk8yagkYArb36I".Hash() + __LINE__.ToInt())));
GetRPCManager().SendRPC(kikAjVIj("9D9946813FCAB48F43BA49B876815A72A6A681", ("DQUmappr0Zypwz".Hash() + __LINE__.ToInt())), kikAjVIj("3B8798A5C68878A140B38DB496B95C4B748AB89757AE70", ("k9KL7JLhShXJ2o".Hash() + __LINE__.ToInt())), new MW6B2fJp2e5yoeg < ref rwSfHNwZ > (UnGIHljbrnTI), true, sender);
return;
}
while (DIMPUFKw != -1) {
rQe8nePTKR9aOZn wordEnd = DIMPUFKw + PQCbfvYB.Length();
for (rQe8nePTKR9aOZn i = 0; i < PQCbfvYB.Length(); i++) {
RSRwLAXQ[DIMPUFKw + i] = kikAjVIj("88", ("X3BrfWjdnRAJpJ".Hash() + __LINE__.ToInt()));
}
DIMPUFKw = IqduHQpx.IndexOfFrom(wordEnd, PQCbfvYB);
}
}
WNcEUoYj.lQnatWUgnquH(mgXTFwgN.GetTierColor(KkcNTOHO));
WNcEUoYj.MgTgIslBfGmT(mgXTFwgN.GetRole(KkcNTOHO));
GetRPCManager().SendRPC(kikAjVIj("493A44725B665C8485A97A6A90BD6FB87E73AB", ("7bDO9yqFN0DqVy".Hash() + __LINE__.ToInt())), kikAjVIj("42817776527A8A4EA04A6C6F427B9AACC0B75FB57C9253", ("Eu2Ts7qhbnT9TN".Hash() + __LINE__.ToInt())), new MW6B2fJp2e5yoeg < ref rwSfHNwZ > (WNcEUoYj));
}
}
lyCi29SFHi3KWSG aVkqAcWuWyxZ(JS2JumdfaA6c1zr str) {
JS2JumdfaA6c1zr ZlpkSafrtHuE = kikAjVIj("416C4D71519DC29FA6C76F824DB366B7A85FA8B0A87BC8BBBA7261346C738A5132388E4580572E4EA5505452A78BA8585E618E9C", ("X6kAcbfjbHis01".Hash() + __LINE__.ToInt()));
return ZlpkSafrtHuE.IndexOf(str) >= 0;
}
XwqDJvrmXw47s97 GetPlayersList(ZtrUPfBzRFKQHHq type, ref OYmakunmewNrsKo ctx, ref vvO9t6rTCeSN1gv sender, ref hMIsyqIQckN9ExE target) {
if (type == CallType.Server) {
riqOfqSht(sender);
}
}
override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
super.InvokeOnConnect(player, identity);
riqOfqSht();
}
XwqDJvrmXw47s97 riqOfqSht(ref vvO9t6rTCeSN1gv sender = NULL) {
ref xR68ZEq0lf5RFm0 < Man > MDEFwVUoy = new xR68ZEq0lf5RFm0 < Man > ;
GetGame().GetPlayers(MDEFwVUoy);
ref xvFTsh2ntHZX9Ni < ref iULXOCxCummq > qTeBuNFGS = new xvFTsh2ntHZX9Ni < ref iULXOCxCummq > ();
foreach(MpIxubMOpL03m1F man: MDEFwVUoy) {
UY2FAPANnDzE8Qh player = UY2FAPANnDzE8Qh.Cast(man);
if (!player)
continue;
qTeBuNFGS.Insert(new iULXOCxCummq(player.GetIdentity().GetName(), player.GetIdentity().GetPlainId(), player.GetIdentity().GetId()));
}
if (sender)
GetRPCManager().SendRPC(kikAjVIj("8841996452768E746BCA2C69979D588E478C9E", ("rYdpFBcVmJcRfy".Hash() + __LINE__.ToInt())), kikAjVIj("42669E7184B990C79AA97462B85465A59A", ("8drcfkzS5rBJlL".Hash() + __LINE__.ToInt())), new wJEWREECrpCFh1t < array < ref iULXOCxCummq >> (qTeBuNFGS), true, sender);
else
GetRPCManager().SendRPC(kikAjVIj("6958867EA58DA39C735C486367CE994E4FC05F", ("TQJjHcZrHPHeZv".Hash() + __LINE__.ToInt())), kikAjVIj("2B976146C9C15F564886567D676D8EC55A", ("NxQOvZ9aKxyPp9".Hash() + __LINE__.ToInt())), new wJEWREECrpCFh1t < array < ref iULXOCxCummq >> (qTeBuNFGS), true);
}
}
