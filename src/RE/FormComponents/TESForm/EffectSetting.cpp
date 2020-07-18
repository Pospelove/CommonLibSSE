#include "RE/FormComponents/TESForm/EffectSetting.h"


namespace RE
{
	auto EffectSetting::GetArchetype() const
		-> Archetype
	{
		return data.archetype;
	}


	ActorValue EffectSetting::GetMagickSkill() const
	{
		return data.associatedSkill;
	}


	std::uint32_t EffectSetting::GetMinimumSkillLevel() const
	{
		return data.minimumSkill;
	}


	bool EffectSetting::HasArchetype(Archetype a_type) const
	{
		return data.archetype == a_type;
	}
}
