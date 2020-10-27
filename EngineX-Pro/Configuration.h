#pragma once
class Configuration :public IAbstractModuleBase, public Singleton<Configuration>
{
private:
public:

	string str0 ="";
	void OnStart()
	{

	}

	void OnStop()
	{
	}

	void OnUpdate()
	{

	}

	void OnRender()
	{
	}

	void OnMenu()
	{

		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::SetNextWindowBgAlpha(0.75f);
		ImGui::BeginChild("ConfBorder", ImVec2(645, 250), true);
	
		if (ImGui::Button("Load Settings"))
		{
			Settings::Load("Settings",FileExtension::GetAppDataDirectory()+"\\EngineX\\");
		}
		
		if (ImGui::Button("Save Settings"))
		{
			Settings::Save("Settings",FileExtension::GetAppDataDirectory() + "\\EngineX\\" );
		}

		


		ImGui::EndChild();
		ImGui::PopStyleVar();
	}

};
