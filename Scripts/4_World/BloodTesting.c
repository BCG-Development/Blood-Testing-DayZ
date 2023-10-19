modded class ActionTestBloodSelf
{
    void ActionTestBloodSelf()
	{
		m_CallbackClass = ActionTestBloodSelfCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override bool HasTarget()
	{
		return false;
	}
		
	override string GetText()
	{
		return "#test_blood";
	}
	
	string hpstatus ( int X )
	{
		string result; 
		if (X == 0) result = "No trace";
		if (X > 0 && X < 200) result = "Initial stage";
		if (X >= 200 && X < 700) result = "Middle stage";
		if (X >= 700 && X <= 1000) result = "Late stage";
		return result;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		PluginLifespan module_lifespan = PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
		int blood_type = action_data.m_Player.GetStatBloodType().Get();
		
		module_lifespan.UpdateBloodType( action_data.m_Player, blood_type );
		module_lifespan.UpdateBloodTypeVisibility( action_data.m_Player, true );
		
		action_data.m_MainItem.Delete();
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );


		EStatLevels immunityLevel = action_data.m_Player.GetImmunityLevel();
		string immunityLevelStr;
		switch (immunityLevel)
		{
			case EStatLevels.GREAT: immunityLevelStr = "BEST"; break;
			case EStatLevels.HIGH: immunityLevelStr = "HIGH"; break;
			case EStatLevels.MEDIUM: immunityLevelStr = "MEDIUM"; break;
			case EStatLevels.LOW: immunityLevelStr = "LOW"; break;
			case EStatLevels.CRITICAL: immunityLevelStr = "CRITICAL"; break;
		}

		SendMessageToClient(action_data.m_Player, "Medical Report:");
		SendMessageToClient(action_data.m_Player, "Immunity Level: " + immunityLevelStr);
		SendMessageToClient(action_data.m_Player, "Food Poisoning: " + action_data.m_Player.GetSingleAgentCount(eAgents.FOOD_POISON).ToString());
		SendMessageToClient(action_data.m_Player, "Cholera: " + hpstatus(action_data.m_Player.GetSingleAgentCount(eAgents.CHOLERA)));
		SendMessageToClient(action_data.m_Player, "Influenza: " + hpstatus(action_data.m_Player.GetSingleAgentCount(eAgents.INFLUENZA)));
		SendMessageToClient(action_data.m_Player, "Salmonella: " + hpstatus(action_data.m_Player.GetSingleAgentCount(eAgents.SALMONELLA)));
		SendMessageToClient(action_data.m_Player, "Wound Infection: " + hpstatus(action_data.m_Player.GetSingleAgentCount(eAgents.WOUND_AGENT)));
		SendMessageToClient(action_data.m_Player, "Chemical Poisoning: " + hpstatus(action_data.m_Player.GetSingleAgentCount(eAgents.CHEMICAL_POISON)));
		
		action_data.m_MainItem.AddHealth("", "", -4);
        
		if (action_data.m_MainItem.GetHealth("GlobalHealth", "Health") < 1)
        {
        action_data.m_MainItem.Delete();
        }
	}	
}