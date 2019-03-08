#pragma once

#include "RE/hkArray.h"  // hkArray
#include "RE/hkbEvent.h"  // hkbEvent
#include "RE/hkbGenerator.h"  // hkbGenerator
#include "RE/hkRefPtr.h"  // hkRefPtr


namespace RE
{
	class hkbStateChooser;
	class hkbStateMachineStateInfo;
	class hkbStateMachineTransitionInfoArray;


	class hkbStateMachine : public hkbGenerator
	{
	public:
		enum class StartStateMode : UInt8
		{
			kDefault = 0,
			kSync = 1,
			kRandom = 2,
			kChooser = 3
		};


		enum class StateMachineSelfTransitionMode : UInt8
		{
			kNoTransition = 0,
			kTransitionToStartState = 1,
			kForceTransitionToStartState = 2
		};


		virtual ~hkbStateMachine();																								// 00

		// override (hkbGenerator)
		virtual hkClass*	GetClassType() const override;																		// 01
		virtual void		CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;	// 02
		virtual void		Unk_03(void) override;																				// 03
		virtual void		Unk_04(void) override;																				// 04
		virtual void		Unk_05(void) override;																				// 05
		virtual void		Unk_06(void) override;																				// 06
		virtual void		Unk_07(void) override;																				// 07
		virtual void		Unk_08(void) override;																				// 08
		virtual void		Unk_09(void) override;																				// 09
		virtual void		Unk_0A(void) override;																				// 0A
		virtual void		Unk_0C(void) override;																				// 0C
		virtual void		Unk_0D(void) override;																				// 0D
		virtual void		Unk_0E(void) override;																				// 0E
		virtual void		Unk_0F(void) override;																				// 0F
		virtual void		Unk_10(void) override;																				// 10
		virtual void		Unk_11(void) override;																				// 11
		virtual void		Unk_12(void) override;																				// 12
		virtual void		Unk_14(void) override;																				// 14
		virtual void		Unk_17(void) override;																				// 17
		virtual void		Unk_18(void) override;																				// 18 - { return 1; }
		virtual void		Unk_19(void) override;																				// 19
		virtual void		Unk_1B(void) override;																				// 1B - { echoNextUpdate = true; }


		// members
		hkbEvent										eventToSendWhenStateOrTransitionChanges;	// 048
		hkRefPtr<hkbStateChooser>						startStateChooser;							// 060
		SInt32											startStateID;								// 068
		SInt32 											returnToPreviousStateEventID;				// 06C
		SInt32 											randomTransitionEventID;					// 070
		SInt32 											transitionToNextHigherStateEventID;			// 074
		SInt32 											transitionToNextLowerStateEventID;			// 078
		SInt32 											syncVariableIndex;							// 07C
		SInt32 											currentStateID;								// 080
		bool 											wrapAroundStateID;							// 084
		SInt8 											maxSimultaneousTransitions;					// 085
		StartStateMode									startStateMode;								// 086
		StateMachineSelfTransitionMode 					selfTransitionMode;							// 087
		bool 											isActive;									// 088
		UInt8 											pad41;										// 089
		UInt16 											pad42;										// 08A
		UInt32 											pad44;										// 08C
		hkArray<hkbStateMachineStateInfo*> 				states;										// 090
		hkRefPtr<hkbStateMachineTransitionInfoArray>	wildcardTransitions;						// 0A0 - hkbStateMachine::TransitionInfoArray
		hkRefVariant 									stateIDToIndexMap;							// 0A8
		hkArray<hkRefVariant> 							activeTransitions;							// 0B0
		hkArray<hkRefVariant> 							transitionFlags;							// 0C0
		hkArray<hkRefVariant> 							wildcardTransitionFlags;					// 0D0
		hkArray<hkRefVariant> 							delayedTransitions;							// 0E0
		float 											timeInState;								// 0F0
		float 											lastLocalTime;								// 0F4
		SInt32 											previousStateID;							// 0F8
		SInt32 											nextStartStateIndexOverride;				// 0FC
		bool 											stateOrTransitionChanged;					// 100
		bool 											echoNextUpdate;								// 101
		UInt16 											currentStateIndexAndEntered;				// 102
		UInt32 											pad0BC;										// 104
	};
	STATIC_ASSERT(sizeof(hkbStateMachine) == 0x108);
}
