class CfgPatches
{
	class BloodTestingDayZ
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Scripts",
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class BloodTestingDayZ
	{
		dir = "BloodTestingDayZ";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BloodTestingDayZ";
		credits = "BCG-Development";
		author = "";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		inputs="";
		dependencies[] = {"Game", "World", "Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = 
				{
					"Blood-Testing-DayZ/Scripts/Common",
					"Blood-Testing-DayZ/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = 
				{
					"Blood-Testing-DayZ/Scripts/Common",
					"Blood-Testing-DayZ/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = 
				{
					"Blood-Testing-DayZ/Scripts/Common",
					"Blood-Testing-DayZ/Scripts/5_Mission"
				};
			};
		};
	};
};
