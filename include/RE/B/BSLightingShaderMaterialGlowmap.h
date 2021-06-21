#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialGlowmap : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialGlowmap;
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterialGlowmap;
		inline static constexpr auto FEATURE = Feature::kGlowMap;

		virtual ~BSLightingShaderMaterialGlowmap();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;                                                                                                                 // 01
		virtual void              CopyMembers(BSShaderMaterial* a_other) override;                                                                                   // 02
		virtual std::uint32_t     ComputeCRC32(void) override;                                                                                                       // 04
		virtual Feature           GetFeature() const override;                                                                                                       // 06 - { return Feature::kGlowMap; }
		virtual void              OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet) override;                                                       // 08
		virtual void              ClearTextures() override;                                                                                                          // 09
		virtual void              ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;  // 0A
		virtual void              GetTextures(void) override;                                                                                                        // 0B

		// members
		NiPointer<NiSourceTexture> glowTexture;  // A0

	protected:
		BSLightingShaderMaterialGlowmap* ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterialGlowmap::ctor);
			REL::Relocation<func_t> func{ REL::ID(100045) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterialGlowmap) == 0xA8);
}