#include "stdafx.h"
#include "MainCore.h"

bool MainCore::DXLoaded = false;
void MainCore::Crack()
{
	switch (Globals::Server)
	{
		//case ServerName::AELDRA:
		//{
		//	DWORD addr1 = Globals::pCPythonNetworkStreamSendAttackPacket + 0x29;
		//	MemoryExtension::MemSet(addr1, 0x90, 16);
		//	break;
		//}
		default:
		{
			break;
		}
	}
}
///##################################################################################################################
bool MainCore::CheckMembers()
{
	string hwid = GetHardwareId();
	if ( hwid == "21D7B04A-523B0BDA-3B9C1E8A-40E0655B")//ja
	{
		return true;
	}
	else if (hwid == "45B6C023-28530FB7-329670E2-22F56148")//ser
	{
		return true;
	}
	else if (hwid == "51A0C122-B9B991A5-C50CE71B-C176E9A6")//adi
	{
		return true;
	}
	else if (hwid == "2CBFC55D-47476FA5-3CE60CE5-36F71640")//kom
	{
		return true;
	}
	else if (hwid == "28C3A75F-5C347AB3-39E4738A-328A642E")
	{
		return true;
	}
	return false;
}

void MainCore::ConsoleOutput(const char* txt, ...)
{
#ifdef DEVELOPER_MODE
	printf(txt);
	printf("\n");
#endif
}

void MainCore::NetworkThread()
{
	Network::Initialize();
	Network::SetRecvBufferSize(9999999);
	Network::SetSendBufferSize(4256);
	if (!Network::Connect(AUTH_IP_ADDRESS, AUTH_PORT))
	{
		ExitProcess(0);
	}
	PacketHandler::SendAuthPacket();
	while (true)
	{
		Network::Process();
		PacketHandler::Process();
		Sleep(1);
	}
}
///##################################################################################################################
void MainCore::Initialize()
{	

#if defined( DEVELOPER_MODE) || defined(_DEBUG)
	if (!MainCore::CheckMembers())
	{
		MessageBox(NULL, "Cheat Wrong Version", "Error", 0);
		exit(0);
	}
#endif
	while (!Device::pDevice || !MainCore::DXLoaded || !PacketHandler::AddressReceived)
	{
		try
		{
			//Globals::ReAddressingLocas();
			Globals::ReDeclarationLocals();
			ConsoleOutput("[+] Wait...");
			Sleep(500);
		}
		catch (...)
		{
			ConsoleOutput("[+] Error...");
			Sleep(1000);
		}
	}
	ConsoleOutput("[+] Application detected.");
	Globals::mainHwnd = (HWND)(*reinterpret_cast<DWORD*>(Globals::iCPythonApplicationInstance + 4));
	MainCore::Crack();
	if (Globals::Server == ServerName::METINPL)
	{
		Settings::FISHBOT_BAIT_LIST.insert(make_pair(make_pair(1, true), make_pair(27798, "Krewetki Słodkowodne")));
		Settings::FISHBOT_KILL_FISH_LIST.insert(make_pair(make_pair(22, true), make_pair(27824, "Weżoglów")));
		Settings::FISHBOT_KILL_FISH_LIST.insert(make_pair(make_pair(23, true), make_pair(27825, "Skaber")));
		Settings::FISHBOT_KILL_FISH_LIST.insert(make_pair(make_pair(24, true), make_pair(27826, "Krab Królewski")));
		Settings::FISHBOT_KILL_FISH_LIST.insert(make_pair(make_pair(25, true), make_pair(27827, "Rak Niebiański")));
		Settings::FISHBOT_DROP_LIST.insert(make_pair(make_pair(42, true), make_pair(27854, "Martwy Weżoglów")));
		Settings::FISHBOT_DROP_LIST.insert(make_pair(make_pair(43, true), make_pair(27855, "Martwy Skaber")));
		Settings::FISHBOT_DROP_LIST.insert(make_pair(make_pair(44, true), make_pair(27856, "Martwy Krab Królewski")));
		Settings::FISHBOT_DROP_LIST.insert(make_pair(make_pair(45, true), make_pair(27857, "Martwy Rak Niebiański")));
		Settings::INVENTORY_PAGE_COUNT = 2;
	}
	Hooks::Initialize();
	string title = "";
	title += "Version ";
	title += DLL_VERSION;
	title += " ";
#ifdef _DEBUG
	title += "Debug";
#else
	title += "Relase";
#endif
	title += " ";
	MiscExtension::ShowBalloon(Globals::mainHwnd, "EngineX", title.c_str(), NULL);
}
///##################################################################################################################
void  MainCore::UpdateLoop()
{
	DelayActions::Update();
	for (map< pair<DWORD, string>, pair<bool, std::shared_ptr<IAbstractModuleBase>>> ::iterator itor = MainCore::moduleList.begin(); itor != MainCore::moduleList.end(); itor++)
	{
		if (itor->second.first)
		{
			itor->second.second->OnUpdate();
		}
	}
}