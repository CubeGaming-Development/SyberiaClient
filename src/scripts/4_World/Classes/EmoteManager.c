modded class EmoteManager
{
	int GetCurrentEmoteID()
	{
		return m_CurrentGestureID;
	}
	
	bool IsPlayerSleeping()
	{
		return GetCurrentEmoteID() == EmoteConstants.ID_EMOTE_LYINGDOWN;
	}
	
	void Update( float deltaT )
	{
		super.Update(deltaT);
		
		if (m_Player.IsRestrained())
			return;
		
		if ( m_Callback )
		{
			if (m_CurrentGestureID == EmoteConstants.ID_EMOTE_SUICIDE && m_Player.GetMindState() == 5)
			{
				if (m_Callback.GetState() == m_Callback.STATE_LOOP_LOOP)
				{
					CommitSuicide();
				}
			}
		}
	}
};