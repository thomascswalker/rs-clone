#include "OSRSClone.h"
#include "PathGrid__pf2614143031.h"
#include "GeneratedCodeHelpers.h"
#include "Runtime/Engine/Classes/Engine/SimpleConstructionScript.h"
#include "Runtime/Engine/Classes/Engine/SCS_Node.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/EngineBaseTypes.h"
#include "Runtime/Engine/Classes/GameFramework/DamageType.h"
#include "Runtime/Engine/Classes/Engine/NetSerialization.h"
#include "Runtime/PhysicsCore/Public/PhysicalMaterials/PhysicalMaterial.h"
#include "Runtime/PhysicsCore/Public/PhysicsSettingsEnums.h"
#include "Runtime/PhysicsCore/Public/PhysicalMaterials/PhysicalMaterialPropertyBase.h"
#include "Runtime/PhysicsCore/Public/Chaos/ChaosEngineInterface.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Materials/MaterialInterface.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterialMask.h"
#include "Runtime/Engine/Classes/Engine/Texture.h"
#include "Runtime/Engine/Classes/EditorFramework/AssetImportData.h"
#include "Runtime/Engine/Classes/Engine/StreamableRenderAsset.h"
#include "Runtime/Engine/Classes/Engine/TextureDefines.h"
#include "Runtime/Engine/Public/PerPlatformProperties.h"
#include "Runtime/Engine/Classes/Engine/AssetUserData.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_AssetUserData.h"
#include "Runtime/Engine/Classes/Materials/MaterialLayersFunctions.h"
#include "Runtime/Engine/Classes/Materials/MaterialFunctionInterface.h"
#include "Runtime/Engine/Classes/EditorFramework/ThumbnailInfo.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpression.h"
#include "Runtime/Engine/Classes/Materials/MaterialFunction.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionComment.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionMaterialFunctionCall.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionFunctionInput.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionFunctionOutput.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphNode.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphPin.h"
#include "Runtime/Engine/Public/MaterialShared.h"
#include "Runtime/Engine/Classes/Engine/BlendableInterface.h"
#include "Runtime/Engine/Public/MaterialCachedData.h"
#include "Runtime/Engine/Classes/Engine/Font.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Classes/Engine/FontImportOptions.h"
#include "Runtime/SlateCore/Public/Fonts/CompositeFont.h"
#include "Runtime/SlateCore/Public/Fonts/FontBulkData.h"
#include "Runtime/SlateCore/Public/Fonts/FontProviderInterface.h"
#include "Runtime/Engine/Classes/VT/RuntimeVirtualTexture.h"
#include "Runtime/Engine/Public/VT/RuntimeVirtualTextureEnum.h"
#include "Runtime/Engine/Classes/VT/VirtualTexture.h"
#include "Runtime/Engine/Classes/Curves/CurveLinearColor.h"
#include "Runtime/Engine/Classes/Curves/CurveBase.h"
#include "Runtime/Engine/Classes/Curves/RichCurve.h"
#include "Runtime/Engine/Classes/Curves/RealCurve.h"
#include "Runtime/Engine/Classes/Curves/IndexedCurve.h"
#include "Runtime/Engine/Classes/Curves/KeyHandle.h"
#include "Runtime/Engine/Classes/Curves/CurveLinearColorAtlas.h"
#include "Runtime/Engine/Classes/Materials/MaterialParameterCollection.h"
#include "Runtime/Landscape/Classes/LandscapeGrassType.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshSocket.h"
#include "Runtime/StaticMeshDescription/Public/StaticMeshDescription.h"
#include "Runtime/MeshDescription/Public/MeshDescriptionBase.h"
#include "Runtime/MeshDescription/Public/MeshTypes.h"
#include "Runtime/Engine/Public/Components.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetup.h"
#include "Runtime/PhysicsCore/Public/BodySetupCore.h"
#include "Runtime/PhysicsCore/Public/BodySetupEnums.h"
#include "Runtime/Engine/Classes/PhysicsEngine/AggregateGeom.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphereElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ShapeElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BoxElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphylElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConvexElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/TaperedCapsuleElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodyInstance.h"
#include "Runtime/PhysicsCore/Public/BodyInstanceCore.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavCollisionBase.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_CollisionDataProvider.h"
#include "Runtime/Engine/Classes/Engine/MeshMerging.h"
#include "Runtime/Engine/Classes/Engine/SubsurfaceProfile.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceBasePropertyOverrides.h"
#include "Runtime/Engine/Public/StaticParameterSet.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Widget.h"
#include "Runtime/UMG/Public/Components/Visual.h"
#include "Runtime/UMG/Public/Components/SlateWrapperTypes.h"
#include "Runtime/UMG/Public/Slate/WidgetTransform.h"
#include "Runtime/SlateCore/Public/Types/SlateEnums.h"
#include "Runtime/SlateCore/Public/Input/NavigationReply.h"
#include "Runtime/SlateCore/Public/Layout/Clipping.h"
#include "Runtime/SlateCore/Public/Layout/Geometry.h"
#include "Runtime/SlateCore/Public/Input/Events.h"
#include "Runtime/SlateCore/Public/Styling/SlateColor.h"
#include "Runtime/SlateCore/Public/Styling/SlateBrush.h"
#include "Runtime/SlateCore/Public/Layout/Margin.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/UMG/Public/Components/PanelSlot.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
#include "Runtime/Engine/Classes/Engine/Player.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Runtime/Engine/Classes/Engine/ScriptViewportClient.h"
#include "Runtime/Engine/Classes/Engine/Console.h"
#include "Runtime/Engine/Classes/Engine/DebugDisplayProperty.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/WorldSettings.h"
#include "Runtime/Engine/Classes/GameFramework/Info.h"
#include "Runtime/Engine/Classes/Components/BillboardComponent.h"
#include "Runtime/Engine/Classes/AI/NavigationSystemConfig.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationTypes.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPhysicsVolume.h"
#include "Runtime/Engine/Classes/GameFramework/PhysicsVolume.h"
#include "Runtime/Engine/Classes/GameFramework/Volume.h"
#include "Runtime/Engine/Classes/Engine/Brush.h"
#include "Runtime/Engine/Classes/Components/BrushComponent.h"
#include "Runtime/Engine/Classes/Engine/BrushBuilder.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsCollisionHandler.h"
#include "Runtime/Engine/Classes/Sound/SoundBase.h"
#include "Runtime/Engine/Classes/Sound/SoundClass.h"
#include "Runtime/Engine/Classes/Sound/SoundModulationDestination.h"
#include "Runtime/AudioExtensions/Public/IAudioModulation.h"
#include "Runtime/Engine/Classes/Sound/AudioOutputTarget.h"
#include "Runtime/Engine/Classes/Sound/SoundWaveLoadingBehavior.h"
#include "Runtime/Engine/Classes/Sound/SoundSubmix.h"
#include "Runtime/Engine/Classes/Sound/SoundSubmixSend.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "Runtime/AudioPlatformConfiguration/Public/AudioCompressionSettings.h"
#include "Runtime/Engine/Classes/Sound/SoundGroups.h"
#include "Runtime/Engine/Classes/Engine/CurveTable.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectSubmix.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectPreset.h"
#include "Runtime/AudioExtensions/Public/ISoundfieldFormat.h"
#include "Runtime/Engine/Classes/Sound/SoundMix.h"
#include "Runtime/Engine/Classes/Sound/SoundConcurrency.h"
#include "Runtime/Engine/Classes/Sound/SoundAttenuation.h"
#include "Runtime/Engine/Classes/Engine/Attenuation.h"
#include "Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "Runtime/AudioExtensions/Public/IAudioExtensionPlugin.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectSource.h"
#include "Runtime/Engine/Classes/Sound/SoundSourceBusSend.h"
#include "Runtime/Engine/Classes/Sound/SoundSourceBus.h"
#include "Runtime/Engine/Classes/Sound/AudioBus.h"
#include "Runtime/Engine/Classes/GameFramework/GameModeBase.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"
#include "Runtime/Engine/Classes/GameFramework/LocalMessage.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineReplStructs.h"
#include "Runtime/CoreUObject/Public/UObject/CoreOnline.h"
#include "Runtime/Engine/Classes/GameFramework/EngineMessage.h"
#include "Runtime/Engine/Classes/GameFramework/GameSession.h"
#include "Runtime/Engine/Classes/GameFramework/GameStateBase.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawn.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPawn.h"
#include "Runtime/Engine/Classes/GameFramework/PawnMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/NavMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/MovementComponent.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Components/ShapeComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreaBase.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/MeshComponent.h"
#include "Runtime/Engine/Classes/Engine/TextureStreamingTypes.h"
#include "Runtime/Engine/Classes/GameFramework/FloatingPawnMovement.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardData.h"
#include "Runtime/Engine/Classes/Engine/DataAsset.h"
#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/BrainComponent.h"
#include "Runtime/AIModule/Classes/AIResourceInterface.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskResource.h"
#include "Runtime/AIModule/Classes/Navigation/PathFollowingComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationData.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationDataInterface.h"
#include "Runtime/Engine/Classes/AI/Navigation/PathFollowingAgentInterface.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTCompositeNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTNode.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskOwnerInterface.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTTaskNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTService.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTAuxiliaryNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTDecorator.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeTypes.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardAssetProvider.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraph.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphSchema.h"
#include "Runtime/Engine/Classes/Engine/Blueprint.h"
#include "Runtime/GameplayTasks/Classes/GameplayTask.h"
#include "Runtime/NavigationSystem/Public/NavFilters/NavigationQueryFilter.h"
#include "Runtime/NavigationSystem/Public/NavAreas/NavArea.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AISense.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionSystem.h"
#include "Runtime/AIModule/Classes/AISubsystem.h"
#include "Runtime/AIModule/Classes/AISystem.h"
#include "Runtime/Engine/Classes/AI/AISystemBase.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeManager.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryManager.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQuery.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryOption.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryGenerator.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryNode.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/Items/EnvQueryItemType.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryTest.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryTypes.h"
#include "Runtime/AIModule/Classes/DataProviders/AIDataProvider.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryInstanceBlueprintWrapper.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EQSQueryResultSourceInterface.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryContext.h"
#include "Runtime/AIModule/Classes/Blueprint/AIAsyncTaskBlueprintProxy.h"
#include "Runtime/AIModule/Classes/AITypes.h"
#include "Runtime/AIModule/Classes/HotSpots/AIHotSpotManager.h"
#include "Runtime/AIModule/Classes/Navigation/NavLocalGridManager.h"
#include "Runtime/AIModule/Classes/Perception/AISenseEvent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig.h"
#include "Runtime/AIModule/Classes/Actions/PawnActionsComponent.h"
#include "Runtime/AIModule/Classes/Actions/PawnAction.h"
#include "Runtime/GameplayTasks/Classes/GameplayTasksComponent.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionListenerInterface.h"
#include "Runtime/AIModule/Classes/GenericTeamAgentInterface.h"
#include "Runtime/Engine/Public/VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawnMovement.h"
#include "Runtime/Engine/Classes/GameFramework/HUD.h"
#include "Runtime/Engine/Classes/Engine/Canvas.h"
#include "Runtime/Engine/Classes/Debug/ReporterGraph.h"
#include "Runtime/Engine/Classes/Debug/ReporterBase.h"
#include "Runtime/Engine/Classes/GameFramework/DebugTextInfo.h"
#include "Runtime/Engine/Classes/Engine/ServerStatReplicator.h"
#include "Runtime/Engine/Classes/GameFramework/GameNetworkManager.h"
#include "Runtime/Engine/Classes/Sound/ReverbSettings.h"
#include "Runtime/Engine/Classes/Sound/ReverbEffect.h"
#include "Runtime/Engine/Classes/Sound/AudioVolume.h"
#include "Runtime/Engine/Classes/Engine/NetConnection.h"
#include "Runtime/Engine/Classes/Engine/ChildConnection.h"
#include "Runtime/Engine/Classes/Engine/PackageMapClient.h"
#include "Runtime/Engine/Classes/Engine/NetDriver.h"
#include "Runtime/Engine/Classes/Engine/Channel.h"
#include "Runtime/Engine/Classes/Engine/ReplicationDriver.h"
#include "Runtime/Engine/Classes/Engine/BookmarkBase.h"
#include "DmgTypeBP_Environmental__pf1001828891.h"
#include "Runtime/Engine/Classes/Engine/BookMark.h"
#include "Runtime/Engine/Classes/Engine/MaterialMerging.h"
#include "Runtime/Engine/Classes/Engine/Level.h"
#include "Runtime/Engine/Classes/Components/ModelComponent.h"
#include "Runtime/Engine/Classes/Engine/LevelActorContainer.h"
#include "Runtime/Engine/Classes/Engine/LevelScriptActor.h"
#include "Runtime/Engine/Classes/Engine/NavigationObjectBase.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAgentInterface.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationDataChunk.h"
#include "Runtime/Engine/Classes/Engine/MapBuildDataRegistry.h"
#include "Runtime/Engine/Classes/Engine/LevelScriptBlueprint.h"
#include "Runtime/Engine/Classes/Engine/BlueprintCore.h"
#include "Runtime/Engine/Classes/Engine/BlueprintGeneratedClass.h"
#include "Runtime/Engine/Classes/Engine/TimelineTemplate.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Runtime/Engine/Classes/Curves/CurveVector.h"
#include "Runtime/Engine/Classes/Engine/InheritableComponentHandler.h"
#include "Runtime/CoreUObject/Public/UObject/CoreNetTypes.h"
#include "Runtime/Engine/Classes/Engine/Breakpoint.h"
#include "Runtime/Engine/Public/Blueprint/BlueprintExtension.h"
#include "Runtime/Engine/Classes/Components/LineBatchComponent.h"
#include "Runtime/Engine/Classes/Engine/LevelStreaming.h"
#include "Runtime/Engine/Classes/Engine/LevelStreamingVolume.h"
#include "Runtime/Engine/Classes/Engine/DemoNetDriver.h"
#include "Runtime/Engine/Classes/Particles/ParticleEventManager.h"
#include "Runtime/Engine/Classes/AI/NavigationSystemBase.h"
#include "Runtime/Engine/Classes/AI/Navigation/AvoidanceManager.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineSession.h"
#include "Runtime/Engine/Classes/Materials/MaterialParameterCollectionInstance.h"
#include "Runtime/Engine/Classes/Engine/WorldComposition.h"
#include "Runtime/Engine/Classes/Particles/WorldPSCPool.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystem.h"
#include "Runtime/Engine/Classes/Particles/ParticleEmitter.h"
#include "Runtime/Engine/Public/ParticleHelper.h"
#include "Runtime/Engine/Classes/Particles/ParticleLODLevel.h"
#include "Runtime/Engine/Classes/Particles/ParticleModuleRequired.h"
#include "Runtime/Engine/Classes/Particles/ParticleModule.h"
#include "Runtime/Engine/Classes/Particles/ParticleSpriteEmitter.h"
#include "Runtime/Engine/Classes/Distributions/DistributionFloat.h"
#include "Runtime/Engine/Classes/Distributions/Distribution.h"
#include "Runtime/Engine/Classes/Particles/SubUVAnimation.h"
#include "Runtime/Engine/Classes/Particles/TypeData/ParticleModuleTypeDataBase.h"
#include "Runtime/Engine/Classes/Particles/Spawn/ParticleModuleSpawn.h"
#include "Runtime/Engine/Classes/Particles/Spawn/ParticleModuleSpawnBase.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventGenerator.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventBase.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventSendToGame.h"
#include "Runtime/Engine/Classes/Particles/Orbit/ParticleModuleOrbit.h"
#include "Runtime/Engine/Classes/Particles/Orbit/ParticleModuleOrbitBase.h"
#include "Runtime/Engine/Classes/Distributions/DistributionVector.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventReceiverBase.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SkinnedMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMesh.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshLODSettings.h"
#include "Runtime/Engine/Classes/Animation/AnimSequence.h"
#include "Runtime/Engine/Classes/Animation/AnimSequenceBase.h"
#include "Runtime/Engine/Classes/Animation/AnimationAsset.h"
#include "Runtime/Engine/Classes/Animation/Skeleton.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSocket.h"
#include "Runtime/Engine/Classes/Animation/SmartName.h"
#include "Runtime/Engine/Classes/Animation/BlendProfile.h"
#include "Runtime/Engine/Public/BoneContainer.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_PreviewMeshProvider.h"
#include "Runtime/Engine/Classes/Animation/Rig.h"
#include "Runtime/Engine/Public/Animation/NodeMappingProviderInterface.h"
#include "Runtime/Engine/Classes/Animation/PreviewAssetAttachComponent.h"
#include "Runtime/Engine/Classes/Animation/AnimMetaData.h"
#include "Runtime/Engine/Classes/Animation/AssetMappingTable.h"
#include "Runtime/Engine/Classes/Animation/PoseAsset.h"
#include "Runtime/Engine/Public/Animation/AnimCurveTypes.h"
#include "Runtime/Engine/Public/Animation/AnimTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimLinkableElement.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "Runtime/Engine/Classes/Animation/AnimCompositeBase.h"
#include "Runtime/Engine/Public/AlphaBlend.h"
#include "Runtime/Engine/Classes/Animation/AnimEnums.h"
#include "Runtime/Engine/Classes/Animation/TimeStretchCurve.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "Runtime/Engine/Classes/Animation/AnimBoneCompressionSettings.h"
#include "Runtime/Engine/Classes/Animation/AnimBoneCompressionCodec.h"
#include "Runtime/Engine/Classes/Animation/AnimCurveCompressionSettings.h"
#include "Runtime/Engine/Classes/Animation/AnimCurveCompressionCodec.h"
#include "Runtime/Engine/Classes/Animation/AnimCurveCompressionCodec_CompressedRichCurve.h"
#include "Runtime/Engine/Classes/Animation/CustomAttributes.h"
#include "Runtime/Engine/Classes/Curves/StringCurve.h"
#include "Runtime/Engine/Classes/Curves/IntegralCurve.h"
#include "Runtime/Engine/Classes/Curves/SimpleCurve.h"
#include "Runtime/Engine/Public/SkeletalMeshReductionSettings.h"
#include "Runtime/Engine/Public/Animation/NodeMappingContainer.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsAsset.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicalAnimationComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintTemplate.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintInstance.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintTypes.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintDrives.h"
#include "Runtime/Engine/Classes/Animation/MorphTarget.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "Runtime/Engine/Public/Animation/PoseSnapshot.h"
#include "Runtime/Engine/Public/Animation/AnimNotifyQueue.h"
#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingAssetBase.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSampling.h"
#include "Runtime/Engine/Public/Animation/SkinWeightProfile.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshEditorData.h"
#include "Runtime/Engine/Public/LODSyncInterface.h"
#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingSimulationInteractor.h"
#include "Runtime/Engine/Classes/Animation/AnimBlueprintGeneratedClass.h"
#include "Runtime/Engine/Classes/Engine/DynamicBlueprintBinding.h"
#include "Runtime/Engine/Classes/Animation/AnimStateMachineTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimClassInterface.h"
#include "Runtime/Engine/Classes/Animation/AnimNodeBase.h"
#include "Runtime/PropertyAccess/Public/PropertyAccess.h"
#include "Runtime/Engine/Public/SingleAnimationPlayData.h"
#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingSimulationFactory.h"
#include "Runtime/Engine/Classes/Animation/AnimBlueprint.h"
#include "Runtime/Engine/Classes/Engine/PoseWatch.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemReplay.h"
#include "Runtime/Engine/Classes/Engine/InterpCurveEdSetup.h"
#include "Runtime/Engine/Classes/Layers/Layer.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/GameFramework/GameUserSettings.h"
#include "Runtime/Engine/Classes/Engine/AssetManager.h"
#include "Runtime/Engine/Classes/Engine/EngineCustomTimeStep.h"
#include "Runtime/Engine/Classes/Engine/TimecodeProvider.h"
#include "Runtime/SlateCore/Public/Styling/SlateTypes.h"
#include "Runtime/UMG/Public/Blueprint/WidgetNavigation.h"
#include "Runtime/SlateCore/Public/Layout/FlowDirection.h"
#include "Runtime/UMG/Public/Binding/PropertyBinding.h"
#include "Runtime/UMG/Public/Binding/DynamicPropertyPath.h"
#include "Runtime/PropertyPath/Public/PropertyPathHelpers.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimation.h"
#include "Runtime/MovieScene/Public/MovieSceneSequence.h"
#include "Runtime/MovieScene/Public/MovieSceneSignedObject.h"
#include "Runtime/MovieScene/Public/MovieSceneObjectBindingID.h"
#include "Runtime/MovieScene/Public/Compilation/MovieSceneCompiledDataManager.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationTemplate.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTrackIdentifier.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationTrack.h"
#include "Runtime/MovieScene/Public/MovieSceneTrack.h"
#include "Runtime/MovieScene/Public/MovieSceneTrackEvaluationField.h"
#include "Runtime/MovieScene/Public/MovieSceneSection.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneCompletionMode.h"
#include "Runtime/MovieScene/Public/Evaluation/Blending/MovieSceneBlendType.h"
#include "Runtime/MovieScene/Public/Generators/MovieSceneEasingFunction.h"
#include "Runtime/MovieScene/Public/MovieSceneFrameMigration.h"
#include "Runtime/MovieScene/Public/Generators/MovieSceneEasingCurves.h"
#include "Runtime/MovieScene/Public/MovieScene.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSegment.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvalTemplate.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTrackImplementation.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceHierarchy.h"
#include "Runtime/MovieScene/Public/MovieSceneSequenceID.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceTransform.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTimeTransform.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTimeWarping.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceInstanceData.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationField.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationKey.h"
#include "Runtime/MovieScene/Public/MovieSceneFwd.h"
#include "Runtime/MovieScene/Public/MovieSceneSpawnable.h"
#include "Runtime/MovieScene/Public/MovieScenePossessable.h"
#include "Runtime/MovieScene/Public/MovieSceneBinding.h"
#include "Runtime/MovieScene/Public/MovieSceneFolder.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimationBinding.h"
#include "Runtime/Slate/Public/Widgets/Layout/Anchors.h"
#include "Runtime/UMG/Public/Animation/UMGSequencePlayer.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationTemplateInstance.h"
#include "Runtime/MovieScene/Public/EntitySystem/MovieSceneEntitySystemLinker.h"
#include "Runtime/MovieScene/Public/EntitySystem/MovieSceneEntitySystemGraphs.h"
#include "Runtime/UMG/Public/Blueprint/DragDropOperation.h"
#include "Runtime/Engine/Classes/Camera/CameraShakeBase.h"
#include "Runtime/Engine/Classes/Camera/CameraAnimInst.h"
#include "Runtime/Engine/Classes/Camera/CameraAnim.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroup.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrack.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInst.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
#include "Runtime/Engine/Classes/Engine/TextureCube.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroupInst.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackMove.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstMove.h"
#include "Runtime/Engine/Classes/Camera/CameraTypes.h"
#include "Runtime/Engine/Classes/Camera/CameraShakeSourceComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraShake.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier.h"
#include "Runtime/Engine/Classes/Particles/EmitterCameraLensEffectBase.h"
#include "Runtime/Engine/Classes/Particles/Emitter.h"
#include "Runtime/Engine/Classes/Components/ArrowComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier_CameraShake.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/UMG/Public/Animation/UMGSequenceTickManager.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"
#include "Runtime/UMG/Public/Components/NamedSlotInterface.h"
#include "Runtime/Engine/Classes/GameFramework/UpdateLevelVisibilityLevelInfo.h"
#include "Runtime/Engine/Classes/Haptics/HapticFeedbackEffect_Base.h"
#include "Runtime/Engine/Classes/Engine/LatentActionManager.h"
#include "Runtime/Engine/Classes/GameFramework/ForceFeedbackEffect.h"
#include "Runtime/Engine/Classes/GameFramework/TouchInterface.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstDirector.h"
#include "Runtime/Engine/Classes/GameFramework/CheatManager.h"
#include "Runtime/Engine/Classes/Engine/DebugCameraController.h"
#include "Runtime/Engine/Classes/Components/DrawFrustumComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementReplication.h"
#include "Runtime/Engine/Classes/GameFramework/RootMotionSource.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationAvoidanceTypes.h"
#include "Runtime/Engine/Public/AI/RVOAvoidanceInterface.h"
#include "Runtime/Engine/Classes/Interfaces/NetworkPredictionInterface.h"
#include "Runtime/Engine/Public/SceneTypes.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavRelevantInterface.h"
#include "Runtime/Engine/Public/HitProxies.h"
#include "Runtime/Engine/Classes/Components/ChildActorComponent.h"
#include "Runtime/Engine/Classes/Matinee/MatineeActor.h"
#include "Runtime/Engine/Classes/Matinee/InterpData.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroupDirector.h"
#include "Runtime/Engine/Classes/Matinee/InterpFilter.h"
#include "Runtime/Engine/Public/ComponentInstanceDataCache.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Engine/Classes/Engine/CollisionProfile.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Kismet/BlueprintMapLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetArrayLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetStringLibrary.h"
#include "PathTileTypes__pf2614143031.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/AudioComponent.h"
#include "Runtime/AudioMixer/Public/Quartz/AudioMixerClockHandle.h"
#include "Runtime/Engine/Classes/Sound/QuartzQuantizationUtilities.h"
#include "Runtime/Engine/Classes/GameFramework/ForceFeedbackAttenuation.h"
#include "Runtime/Engine/Classes/Components/ForceFeedbackComponent.h"
#include "Runtime/Engine/Classes/Sound/DialogueWave.h"
#include "Runtime/Engine/Classes/Sound/DialogueTypes.h"
#include "Runtime/Engine/Classes/Sound/DialogueVoice.h"
#include "Runtime/Engine/Classes/Sound/DialogueSoundWaveProxy.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "Runtime/Engine/Classes/GameFramework/SaveGame.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStaticsTypes.h"


#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
PRAGMA_DISABLE_OPTIMIZATION
APathGrid_C__pf2614143031::APathGrid_C__pf2614143031(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
	bpv__Scene__pf = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	bpv__Billboard__pf = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	RootComponent = bpv__Scene__pf;
	bpv__Scene__pf->CreationMethod = EComponentCreationMethod::Native;
	static TWeakFieldPtr<FProperty> __Local__1{};
	const FProperty* __Local__0 = __Local__1.Get();
	if (nullptr == __Local__0)
	{
		__Local__0 = (UActorComponent::StaticClass())->FindPropertyByName(FName(TEXT("bCanEverAffectNavigation")));
		check(__Local__0);
		__Local__1 = __Local__0;
	}
	(((FBoolProperty*)__Local__0)->SetPropertyValue_InContainer((bpv__Scene__pf), false, 0));
	bpv__Billboard__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__Billboard__pf->AttachToComponent(bpv__Scene__pf, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__Billboard__pf->Sprite = CastChecked<UTexture2D>(CastChecked<UDynamicClass>(APathGrid_C__pf2614143031::StaticClass())->UsedAssets[0], ECastCheckedType::NullAllowed);
	bpv__Billboard__pf->bIsScreenSizeScaled = true;
	bpv__Billboard__pf->ScreenSize = 0.010000f;
	(((FBoolProperty*)__Local__0)->SetPropertyValue_InContainer((bpv__Billboard__pf), false, 0));
	bpv__GridLocation__pf = FVector(0.000000, 0.000000, 0.000000);
	bpv__GridSizeWorld__pf = FVector2D(0.000000, 0.000000);
	bpv__GridBoundsColor__pf = FLinearColor(0.000000, 0.000000, 0.000000, 0.000000);
	bpv__ShowGrid__pf = true;
	bpv__TileSize__pf = 50.000000f;
	bpv__TileGap__pf = 5.000000f;
	bpv__TileData__pf = {};
	bpv__SelectedTile__pf = nullptr;
	bpv__HoveredTile__pf = nullptr;
	bpv__Path___pf = TArray<APathTile_C__pf2614143031*> ();
	auto& __Local__2 = (*(AccessPrivateProperty<EActorUpdateOverlapsMethod >((this), AActor::__PPO__DefaultUpdateOverlapsMethodDuringLevelStreaming() )));
	__Local__2 = EActorUpdateOverlapsMethod::OnlyUpdateMovable;
}
PRAGMA_ENABLE_OPTIMIZATION
void APathGrid_C__pf2614143031::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
	if(bpv__Scene__pf)
	{
		bpv__Scene__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__Billboard__pf)
	{
		bpv__Billboard__pf->CreationMethod = EComponentCreationMethod::Native;
	}
}
PRAGMA_DISABLE_OPTIMIZATION
void APathGrid_C__pf2614143031::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
{
	ensure(0 == InDynamicClass->ReferencedConvertedFields.Num());
	ensure(0 == InDynamicClass->MiscConvertedSubobjects.Num());
	ensure(0 == InDynamicClass->DynamicBindingObjects.Num());
	ensure(0 == InDynamicClass->ComponentTemplates.Num());
	ensure(0 == InDynamicClass->Timelines.Num());
	ensure(0 == InDynamicClass->ComponentClassOverrides.Num());
	ensure(nullptr == InDynamicClass->AnimClassImplementation);
	InDynamicClass->AssembleReferenceTokenStream();
	// List of all referenced converted enums
	InDynamicClass->ReferencedConvertedFields.Add(LoadObject<UEnum>(nullptr, TEXT("/Game/Blueprints/Pathfinding/PathTileTypes.PathTileTypes")));
	// List of all referenced converted classes
	InDynamicClass->ReferencedConvertedFields.Add(APathTile_C__pf2614143031::StaticClass());
	FConvertedBlueprintsDependencies::FillUsedAssetsInDynamicClass(InDynamicClass, &__StaticDependencies_DirectlyUsedAssets);
	auto __Local__3 = NewObject<USceneComponent>(InDynamicClass, USceneComponent::StaticClass(), TEXT("DefaultSceneRoot_GEN_VARIABLE"), (EObjectFlags)0x00280029);
	InDynamicClass->ComponentTemplates.Add(__Local__3);
	static TWeakFieldPtr<FProperty> __Local__5{};
	const FProperty* __Local__4 = __Local__5.Get();
	if (nullptr == __Local__4)
	{
		__Local__4 = (UActorComponent::StaticClass())->FindPropertyByName(FName(TEXT("bCanEverAffectNavigation")));
		check(__Local__4);
		__Local__5 = __Local__4;
	}
	(((FBoolProperty*)__Local__4)->SetPropertyValue_InContainer((__Local__3), false, 0));
}
PRAGMA_ENABLE_OPTIMIZATION
void APathGrid_C__pf2614143031::bpf__ExecuteUbergraph_PathGrid__pf_0(int32 bpp__EntryPoint__pf)
{
	bool bpfv__CallFunc_IsValid_ReturnValue_1__pf{};
	bool bpfv__CallFunc_IsValid_ReturnValue_2__pf{};
	bool bpfv__CallFunc_IsValid_ReturnValue_3__pf{};
	bool bpfv__CallFunc_BooleanAND_ReturnValue__pf{};
	int32 __CurrentState = bpp__EntryPoint__pf;
	do
	{
		switch( __CurrentState )
		{
		case 1:
			{
				bpf__ClearxPath__pfT();
			}
		case 2:
			{
				bpfv__CallFunc_IsValid_ReturnValue_2__pf = UKismetSystemLibrary::IsValid(bpv__SelectedTile__pf);
				bpfv__CallFunc_IsValid_ReturnValue_3__pf = UKismetSystemLibrary::IsValid(bpv__HoveredTile__pf);
				bpfv__CallFunc_BooleanAND_ReturnValue__pf = UKismetMathLibrary::BooleanAND(bpfv__CallFunc_IsValid_ReturnValue_2__pf, bpfv__CallFunc_IsValid_ReturnValue_3__pf);
				if (!bpfv__CallFunc_BooleanAND_ReturnValue__pf)
				{
					__CurrentState = -1;
					break;
				}
			}
		case 3:
			{
				bpf__FindPathToTarget__pf(bpv__SelectedTile__pf, bpv__HoveredTile__pf);
				__CurrentState = -1;
				break;
			}
		case 4:
			{
			}
		case 5:
			{
				bpfv__CallFunc_IsValid_ReturnValue_1__pf = UKismetSystemLibrary::IsValid(bpv__HoveredTile__pf);
				if (!bpfv__CallFunc_IsValid_ReturnValue_1__pf)
				{
					__CurrentState = 9;
					break;
				}
			}
		case 6:
			{
			}
		case 7:
			{
				if(::IsValid(bpv__HoveredTile__pf))
				{
					bpv__HoveredTile__pf->bpf__DehoverTile__pf();
				}
			}
		case 8:
			{
				bpv__HoveredTile__pf = b0l__K2Node_CustomEvent_Tile__pf;
				__CurrentState = 1;
				break;
			}
		case 9:
			{
				__CurrentState = 8;
				break;
			}
		case 20:
			{
			}
		case 21:
			{
				__CurrentState = 4;
				break;
			}
		default:
			break;
		}
	} while( __CurrentState != -1 );
}
void APathGrid_C__pf2614143031::bpf__ExecuteUbergraph_PathGrid__pf_1(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 12);
	bpf__CreateMapData__pf();
	return; // KCST_GotoReturn
}
void APathGrid_C__pf2614143031::bpf__ExecuteUbergraph_PathGrid__pf_2(int32 bpp__EntryPoint__pf)
{
	bool bpfv__CallFunc_IsValid_ReturnValue__pf{};
	int32 __CurrentState = bpp__EntryPoint__pf;
	do
	{
		switch( __CurrentState )
		{
		case 10:
			{
			}
		case 11:
			{
				bpv__SelectedTile__pf = b0l__K2Node_CustomEvent_Tile_1__pf;
				__CurrentState = -1;
				break;
			}
		case 14:
			{
			}
		case 15:
			{
			}
		case 16:
			{
			}
		case 17:
			{
				bpfv__CallFunc_IsValid_ReturnValue__pf = UKismetSystemLibrary::IsValid(bpv__SelectedTile__pf);
				if (!bpfv__CallFunc_IsValid_ReturnValue__pf)
				{
					__CurrentState = 10;
					break;
				}
			}
		case 18:
			{
			}
		case 19:
			{
				if(::IsValid(bpv__SelectedTile__pf))
				{
					bpv__SelectedTile__pf->bpf__DeselectTile__pf();
				}
				__CurrentState = 11;
				break;
			}
		default:
			break;
		}
	} while( __CurrentState != -1 );
}
void APathGrid_C__pf2614143031::bpf__OnTileHovered__pf(APathTile_C__pf2614143031* bpp__Tile__pf)
{
	b0l__K2Node_CustomEvent_Tile__pf = bpp__Tile__pf;
	bpf__ExecuteUbergraph_PathGrid__pf_0(20);
}
void APathGrid_C__pf2614143031::bpf__OnTileSelected__pf(APathTile_C__pf2614143031* bpp__Tile__pf)
{
	b0l__K2Node_CustomEvent_Tile_1__pf = bpp__Tile__pf;
	bpf__ExecuteUbergraph_PathGrid__pf_2(14);
}
void APathGrid_C__pf2614143031::bpf__ReceiveBeginPlay__pf()
{
	bpf__ExecuteUbergraph_PathGrid__pf_1(12);
}
void APathGrid_C__pf2614143031::bpf__GetOrigin__pf(/*out*/ FVector& bpp__Position__pf)
{
	float bpfv__CallFunc_BreakVector2D_X__pf{};
	float bpfv__CallFunc_BreakVector2D_Y__pf{};
	FVector bpfv__CallFunc_GetForwardVector_ReturnValue__pf(EForceInit::ForceInit);
	FVector bpfv__CallFunc_Multiply_VectorFloat_ReturnValue__pf(EForceInit::ForceInit);
	float bpfv__CallFunc_BreakVector2D_X_1__pf{};
	float bpfv__CallFunc_BreakVector2D_Y_1__pf{};
	FVector bpfv__CallFunc_GetRightVector_ReturnValue__pf(EForceInit::ForceInit);
	FVector bpfv__CallFunc_Multiply_VectorFloat_ReturnValue_1__pf(EForceInit::ForceInit);
	FVector bpfv__CallFunc_Subtract_VectorVector_ReturnValue__pf(EForceInit::ForceInit);
	FVector bpfv__CallFunc_Subtract_VectorVector_ReturnValue_1__pf(EForceInit::ForceInit);
	UKismetMathLibrary::BreakVector2D(bpv__GridSizeWorld__pf, /*out*/ bpfv__CallFunc_BreakVector2D_X__pf, /*out*/ bpfv__CallFunc_BreakVector2D_Y__pf);
	if(::IsValid(bpv__Scene__pf))
	{
		bpfv__CallFunc_GetForwardVector_ReturnValue__pf = bpv__Scene__pf->USceneComponent::GetForwardVector();
	}
	bpfv__CallFunc_Multiply_VectorFloat_ReturnValue__pf = UKismetMathLibrary::Multiply_VectorFloat(bpfv__CallFunc_GetForwardVector_ReturnValue__pf, bpfv__CallFunc_BreakVector2D_Y__pf);
	UKismetMathLibrary::BreakVector2D(bpv__GridSizeWorld__pf, /*out*/ bpfv__CallFunc_BreakVector2D_X_1__pf, /*out*/ bpfv__CallFunc_BreakVector2D_Y_1__pf);
	if(::IsValid(bpv__Scene__pf))
	{
		bpfv__CallFunc_GetRightVector_ReturnValue__pf = bpv__Scene__pf->USceneComponent::GetRightVector();
	}
	bpfv__CallFunc_Multiply_VectorFloat_ReturnValue_1__pf = UKismetMathLibrary::Multiply_VectorFloat(bpfv__CallFunc_GetRightVector_ReturnValue__pf, bpfv__CallFunc_BreakVector2D_X_1__pf);
	bpfv__CallFunc_Subtract_VectorVector_ReturnValue__pf = UKismetMathLibrary::Subtract_VectorVector(bpv__GridLocation__pf, bpfv__CallFunc_Multiply_VectorFloat_ReturnValue_1__pf);
	bpfv__CallFunc_Subtract_VectorVector_ReturnValue_1__pf = UKismetMathLibrary::Subtract_VectorVector(bpfv__CallFunc_Subtract_VectorVector_ReturnValue__pf, bpfv__CallFunc_Multiply_VectorFloat_ReturnValue__pf);
	bpp__Position__pf = bpfv__CallFunc_Subtract_VectorVector_ReturnValue_1__pf;
}
void APathGrid_C__pf2614143031::bpf__GetTileCount__pf(/*out*/ int32& bpp__GridTileX__pf, /*out*/ int32& bpp__GridTileY__pf)
{
	FVector2D bpfv__CallFunc_Divide_Vector2DFloat_ReturnValue__pf(EForceInit::ForceInit);
	float bpfv__CallFunc_BreakVector2D_X__pf{};
	float bpfv__CallFunc_BreakVector2D_Y__pf{};
	int32 bpfv__CallFunc_Round_ReturnValue__pf{};
	int32 bpfv__CallFunc_Round_ReturnValue_1__pf{};
	int32 bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf{};
	int32 bpfv__CallFunc_Subtract_IntInt_ReturnValue_1__pf{};
	bpfv__CallFunc_Divide_Vector2DFloat_ReturnValue__pf = UKismetMathLibrary::Divide_Vector2DFloat(bpv__GridSizeWorld__pf, bpv__TileSize__pf);
	UKismetMathLibrary::BreakVector2D(bpfv__CallFunc_Divide_Vector2DFloat_ReturnValue__pf, /*out*/ bpfv__CallFunc_BreakVector2D_X__pf, /*out*/ bpfv__CallFunc_BreakVector2D_Y__pf);
	bpfv__CallFunc_Round_ReturnValue__pf = UKismetMathLibrary::Round(bpfv__CallFunc_BreakVector2D_X__pf);
	bpfv__CallFunc_Round_ReturnValue_1__pf = UKismetMathLibrary::Round(bpfv__CallFunc_BreakVector2D_Y__pf);
	bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf = UKismetMathLibrary::Subtract_IntInt(bpfv__CallFunc_Round_ReturnValue__pf, 1);
	bpfv__CallFunc_Subtract_IntInt_ReturnValue_1__pf = UKismetMathLibrary::Subtract_IntInt(bpfv__CallFunc_Round_ReturnValue_1__pf, 1);
	bpp__GridTileX__pf = bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf;
	bpp__GridTileY__pf = bpfv__CallFunc_Subtract_IntInt_ReturnValue_1__pf;
}
bool  APathGrid_C__pf2614143031::bpf__TraceTile__pf(const FVector bpp__Position__pf__const, ETraceTypeQuery bpp__Channel__pf)
{
	typedef FVector  T__Local__6;
	T__Local__6& bpp__Position__pf = *const_cast<T__Local__6 *>(&bpp__Position__pf__const);
	bool bpp__ReturnValue__pf{};
	TArray<AActor*> bpfv__Temp_object_Variable__pf{};
	float bpfv__CallFunc_GetRealTileSize_Size__pf{};
	FHitResult bpfv__CallFunc_SphereTraceSingle_OutHit__pf{};
	bool bpfv__CallFunc_SphereTraceSingle_ReturnValue__pf{};
	bpf__GetRealTileSize__pf(/*out*/ bpfv__CallFunc_GetRealTileSize_Size__pf);
	bpfv__CallFunc_SphereTraceSingle_ReturnValue__pf = UKismetSystemLibrary::SphereTraceSingle(this, bpp__Position__pf, bpp__Position__pf, bpfv__CallFunc_GetRealTileSize_Size__pf, bpp__Channel__pf, false, bpfv__Temp_object_Variable__pf, EDrawDebugTrace::None, /*out*/ bpfv__CallFunc_SphereTraceSingle_OutHit__pf, true, FLinearColor(1.000000,0.000000,0.000000,1.000000), FLinearColor(0.000000,1.000000,0.000000,1.000000), 20.000000);
	bpp__ReturnValue__pf = bpfv__CallFunc_SphereTraceSingle_ReturnValue__pf;
	return bpp__ReturnValue__pf;
}
void APathGrid_C__pf2614143031::bpf__GetRealTileSize__pf(/*out*/ float& bpp__Size__pf)
{
	float bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf{};
	bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Subtract_FloatFloat(bpv__TileSize__pf, bpv__TileGap__pf);
	bpp__Size__pf = bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf;
}
void APathGrid_C__pf2614143031::bpf__TilePositionFromCoordinate__pf(int32 bpp__X__pf, int32 bpp__Y__pf, /*out*/ FVector& bpp__Position__pf)
{
	float bpfv__CallFunc_Multiply_FloatFloat_ReturnValue__pf{};
	FVector bpfv__CallFunc_GetForwardVector_ReturnValue__pf(EForceInit::ForceInit);
	float bpfv__CallFunc_Multiply_IntFloat_ReturnValue__pf{};
	float bpfv__CallFunc_Add_FloatFloat_ReturnValue__pf{};
	float bpfv__CallFunc_Multiply_FloatFloat_ReturnValue_1__pf{};
	FVector bpfv__CallFunc_Multiply_VectorFloat_ReturnValue__pf(EForceInit::ForceInit);
	float bpfv__CallFunc_Multiply_IntFloat_ReturnValue_1__pf{};
	float bpfv__CallFunc_Add_FloatFloat_ReturnValue_1__pf{};
	FVector bpfv__CallFunc_GetRightVector_ReturnValue__pf(EForceInit::ForceInit);
	FVector bpfv__CallFunc_GetOrigin_Position__pf(EForceInit::ForceInit);
	FVector bpfv__CallFunc_Multiply_VectorFloat_ReturnValue_1__pf(EForceInit::ForceInit);
	FVector bpfv__CallFunc_Add_VectorVector_ReturnValue__pf(EForceInit::ForceInit);
	FVector bpfv__CallFunc_Add_VectorVector_ReturnValue_1__pf(EForceInit::ForceInit);
	bpfv__CallFunc_Multiply_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Multiply_FloatFloat(bpv__TileSize__pf, 2.000000);
	if(::IsValid(bpv__Scene__pf))
	{
		bpfv__CallFunc_GetForwardVector_ReturnValue__pf = bpv__Scene__pf->USceneComponent::GetForwardVector();
	}
	bpfv__CallFunc_Multiply_IntFloat_ReturnValue__pf = UKismetMathLibrary::Multiply_IntFloat(bpp__Y__pf, bpfv__CallFunc_Multiply_FloatFloat_ReturnValue__pf);
	bpfv__CallFunc_Add_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Add_FloatFloat(bpfv__CallFunc_Multiply_IntFloat_ReturnValue__pf, bpv__TileSize__pf);
	bpfv__CallFunc_Multiply_FloatFloat_ReturnValue_1__pf = UKismetMathLibrary::Multiply_FloatFloat(bpv__TileSize__pf, 2.000000);
	bpfv__CallFunc_Multiply_VectorFloat_ReturnValue__pf = UKismetMathLibrary::Multiply_VectorFloat(bpfv__CallFunc_GetForwardVector_ReturnValue__pf, bpfv__CallFunc_Add_FloatFloat_ReturnValue__pf);
	bpfv__CallFunc_Multiply_IntFloat_ReturnValue_1__pf = UKismetMathLibrary::Multiply_IntFloat(bpp__X__pf, bpfv__CallFunc_Multiply_FloatFloat_ReturnValue_1__pf);
	bpfv__CallFunc_Add_FloatFloat_ReturnValue_1__pf = UKismetMathLibrary::Add_FloatFloat(bpfv__CallFunc_Multiply_IntFloat_ReturnValue_1__pf, bpv__TileSize__pf);
	if(::IsValid(bpv__Scene__pf))
	{
		bpfv__CallFunc_GetRightVector_ReturnValue__pf = bpv__Scene__pf->USceneComponent::GetRightVector();
	}
	bpf__GetOrigin__pf(/*out*/ bpfv__CallFunc_GetOrigin_Position__pf);
	bpfv__CallFunc_Multiply_VectorFloat_ReturnValue_1__pf = UKismetMathLibrary::Multiply_VectorFloat(bpfv__CallFunc_GetRightVector_ReturnValue__pf, bpfv__CallFunc_Add_FloatFloat_ReturnValue_1__pf);
	bpfv__CallFunc_Add_VectorVector_ReturnValue__pf = UKismetMathLibrary::Add_VectorVector(bpfv__CallFunc_GetOrigin_Position__pf, bpfv__CallFunc_Multiply_VectorFloat_ReturnValue_1__pf);
	bpfv__CallFunc_Add_VectorVector_ReturnValue_1__pf = UKismetMathLibrary::Add_VectorVector(bpfv__CallFunc_Add_VectorVector_ReturnValue__pf, bpfv__CallFunc_Multiply_VectorFloat_ReturnValue__pf);
	bpp__Position__pf = bpfv__CallFunc_Add_VectorVector_ReturnValue_1__pf;
}
void APathGrid_C__pf2614143031::bpf__CreateMapData__pf()
{
	APathTile_C__pf2614143031* bpfv__Tile__pf{};
	E__PathTileTypes__pf bpfv__Type__pf{};
	bool bpfv__Walkable__pf{};
	FVector bpfv__TilePosition__pf(EForceInit::ForceInit);
	int32 bpfv__Y__pf{};
	int32 bpfv__X__pf{};
	bool bpfv__CallFunc_TraceTile_ReturnValue__pf{};
	bool bpfv__CallFunc_TraceTile_ReturnValue_1__pf{};
	bool bpfv__CallFunc_Not_PreBool_ReturnValue__pf{};
	int32 bpfv__Temp_int_Variable__pf{};
	bool bpfv__CallFunc_BooleanAND_ReturnValue__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue__pf{};
	int32 bpfv__Temp_int_Variable_1__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf{};
	float bpfv__CallFunc_Conv_IntToFloat_ReturnValue__pf{};
	float bpfv__CallFunc_Conv_IntToFloat_ReturnValue_1__pf{};
	FVector2D bpfv__CallFunc_MakeVector2D_ReturnValue__pf(EForceInit::ForceInit);
	FTransform bpfv__CallFunc_Conv_VectorToTransform_ReturnValue__pf{};
	AActor* bpfv__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf{};
	APathTile_C__pf2614143031* bpfv__CallFunc_FinishSpawningActor_ReturnValue__pf{};
	FVector bpfv__CallFunc_K2_GetComponentLocation_ReturnValue__pf(EForceInit::ForceInit);
	float bpfv__CallFunc_Conv_IntToFloat_ReturnValue_2__pf{};
	float bpfv__CallFunc_Conv_IntToFloat_ReturnValue_3__pf{};
	FVector2D bpfv__CallFunc_MakeVector2D_ReturnValue_1__pf(EForceInit::ForceInit);
	FVector bpfv__CallFunc_TilePositionFromCoordinate_Position__pf(EForceInit::ForceInit);
	int32 bpfv__CallFunc_GetTileCount_GridTileX__pf{};
	int32 bpfv__CallFunc_GetTileCount_GridTileY__pf{};
	bool bpfv__CallFunc_LessEqual_IntInt_ReturnValue__pf{};
	bool bpfv__CallFunc_LessEqual_IntInt_ReturnValue_1__pf{};
	TArray< int32, TInlineAllocator<8> > __StateStack;

	int32 __CurrentState = 38;
	do
	{
		switch( __CurrentState )
		{
		case 38:
			{
			}
		case 1:
			{
				bpfv__TilePosition__pf = FVector(0.000000,0.000000,0.000000);
			}
		case 2:
			{
				if(::IsValid(bpv__Scene__pf))
				{
					bpfv__CallFunc_K2_GetComponentLocation_ReturnValue__pf = bpv__Scene__pf->USceneComponent::K2_GetComponentLocation();
				}
				bpv__GridLocation__pf = bpfv__CallFunc_K2_GetComponentLocation_ReturnValue__pf;
			}
		case 3:
			{
			}
		case 4:
			{
			}
		case 5:
			{
				bpfv__Temp_int_Variable_1__pf = 0;
			}
		case 6:
			{
				bpf__GetTileCount__pf(/*out*/ bpfv__CallFunc_GetTileCount_GridTileX__pf, /*out*/ bpfv__CallFunc_GetTileCount_GridTileY__pf);
				bpfv__CallFunc_LessEqual_IntInt_ReturnValue_1__pf = UKismetMathLibrary::LessEqual_IntInt(bpfv__Temp_int_Variable_1__pf, bpfv__CallFunc_GetTileCount_GridTileX__pf);
				if (!bpfv__CallFunc_LessEqual_IntInt_ReturnValue_1__pf)
				{
					__CurrentState = 10;
					break;
				}
			}
		case 7:
			{
				__StateStack.Push(8);
				__CurrentState = 11;
				break;
			}
		case 8:
			{
			}
		case 9:
			{
				bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf = UKismetMathLibrary::Add_IntInt(bpfv__Temp_int_Variable_1__pf, 1);
				bpfv__Temp_int_Variable_1__pf = bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf;
				__CurrentState = 6;
				break;
			}
		case 10:
			{
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 11:
			{
			}
		case 12:
			{
				bpfv__X__pf = bpfv__Temp_int_Variable_1__pf;
			}
		case 13:
			{
			}
		case 14:
			{
			}
		case 15:
			{
				bpfv__Temp_int_Variable__pf = 0;
			}
		case 16:
			{
				bpf__GetTileCount__pf(/*out*/ bpfv__CallFunc_GetTileCount_GridTileX__pf, /*out*/ bpfv__CallFunc_GetTileCount_GridTileY__pf);
				bpfv__CallFunc_LessEqual_IntInt_ReturnValue__pf = UKismetMathLibrary::LessEqual_IntInt(bpfv__Temp_int_Variable__pf, bpfv__CallFunc_GetTileCount_GridTileY__pf);
				if (!bpfv__CallFunc_LessEqual_IntInt_ReturnValue__pf)
				{
					__CurrentState = 31;
					break;
				}
			}
		case 17:
			{
				__StateStack.Push(18);
				__CurrentState = 20;
				break;
			}
		case 18:
			{
			}
		case 19:
			{
				bpfv__CallFunc_Add_IntInt_ReturnValue__pf = UKismetMathLibrary::Add_IntInt(bpfv__Temp_int_Variable__pf, 1);
				bpfv__Temp_int_Variable__pf = bpfv__CallFunc_Add_IntInt_ReturnValue__pf;
				__CurrentState = 16;
				break;
			}
		case 20:
			{
			}
		case 21:
			{
				bpfv__Y__pf = bpfv__Temp_int_Variable__pf;
			}
		case 22:
			{
				bpf__TilePositionFromCoordinate__pf(bpfv__X__pf, bpfv__Y__pf, /*out*/ bpfv__CallFunc_TilePositionFromCoordinate_Position__pf);
				bpfv__TilePosition__pf = bpfv__CallFunc_TilePositionFromCoordinate_Position__pf;
			}
		case 23:
			{
				bpfv__CallFunc_TraceTile_ReturnValue__pf = bpf__TraceTile__pf(bpfv__TilePosition__pf, ETraceTypeQuery::TraceTypeQuery4);
				bpfv__CallFunc_TraceTile_ReturnValue_1__pf = bpf__TraceTile__pf(bpfv__TilePosition__pf, ETraceTypeQuery::TraceTypeQuery3);
				bpfv__CallFunc_Not_PreBool_ReturnValue__pf = UKismetMathLibrary::Not_PreBool(bpfv__CallFunc_TraceTile_ReturnValue__pf);
				bpfv__CallFunc_BooleanAND_ReturnValue__pf = UKismetMathLibrary::BooleanAND(bpfv__CallFunc_TraceTile_ReturnValue_1__pf, bpfv__CallFunc_Not_PreBool_ReturnValue__pf);
				bpfv__Walkable__pf = bpfv__CallFunc_BooleanAND_ReturnValue__pf;
			}
		case 24:
			{
				__StateStack.Push(25);
				__CurrentState = 28;
				break;
			}
		case 25:
			{
				__StateStack.Push(26);
				__CurrentState = 32;
				break;
			}
		case 26:
			{
			}
		case 27:
			{
				bpfv__CallFunc_Conv_IntToFloat_ReturnValue_2__pf = UKismetMathLibrary::Conv_IntToFloat(bpfv__Y__pf);
				bpfv__CallFunc_Conv_IntToFloat_ReturnValue_3__pf = UKismetMathLibrary::Conv_IntToFloat(bpfv__X__pf);
				bpfv__CallFunc_MakeVector2D_ReturnValue_1__pf = UKismetMathLibrary::MakeVector2D(bpfv__CallFunc_Conv_IntToFloat_ReturnValue_3__pf, bpfv__CallFunc_Conv_IntToFloat_ReturnValue_2__pf);
				FCustomThunkTemplates::Map_Add(bpv__TileData__pf, bpfv__CallFunc_MakeVector2D_ReturnValue_1__pf, bpfv__Tile__pf);
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 28:
			{
				if (!bpfv__Walkable__pf)
				{
					__CurrentState = 30;
					break;
				}
			}
		case 29:
			{
				bpfv__Type__pf = E__PathTileTypes__pf::NewEnumerator1;
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 30:
			{
				bpfv__Type__pf = E__PathTileTypes__pf::NewEnumerator2;
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 31:
			{
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 32:
			{
				bpfv__CallFunc_Conv_VectorToTransform_ReturnValue__pf = UKismetMathLibrary::Conv_VectorToTransform(bpfv__TilePosition__pf);
				bpfv__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, APathTile_C__pf2614143031::StaticClass(), bpfv__CallFunc_Conv_VectorToTransform_ReturnValue__pf, ESpawnActorCollisionHandlingMethod::Undefined, ((AActor*)nullptr));
			}
		case 33:
			{
				bpfv__CallFunc_Conv_VectorToTransform_ReturnValue__pf = UKismetMathLibrary::Conv_VectorToTransform(bpfv__TilePosition__pf);
				bpfv__CallFunc_FinishSpawningActor_ReturnValue__pf = CastChecked<APathTile_C__pf2614143031>(UGameplayStatics::FinishSpawningActor(bpfv__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf, bpfv__CallFunc_Conv_VectorToTransform_ReturnValue__pf), ECastCheckedType::NullAllowed);
			}
		case 34:
			{
				bpfv__Tile__pf = bpfv__CallFunc_FinishSpawningActor_ReturnValue__pf;
			}
		case 35:
			{
				if(::IsValid(bpfv__Tile__pf))
				{
					bpfv__Tile__pf->bpv__Type__pf = bpfv__Type__pf;
				}
			}
		case 36:
			{
				bpfv__CallFunc_Conv_IntToFloat_ReturnValue__pf = UKismetMathLibrary::Conv_IntToFloat(bpfv__Y__pf);
				bpfv__CallFunc_Conv_IntToFloat_ReturnValue_1__pf = UKismetMathLibrary::Conv_IntToFloat(bpfv__X__pf);
				bpfv__CallFunc_MakeVector2D_ReturnValue__pf = UKismetMathLibrary::MakeVector2D(bpfv__CallFunc_Conv_IntToFloat_ReturnValue_1__pf, bpfv__CallFunc_Conv_IntToFloat_ReturnValue__pf);
				if(::IsValid(bpfv__Tile__pf))
				{
					bpfv__Tile__pf->bpv__Index__pf = bpfv__CallFunc_MakeVector2D_ReturnValue__pf;
				}
			}
		case 37:
			{
				if(::IsValid(bpfv__Tile__pf))
				{
					bpfv__Tile__pf->bpv__Grid__pf = this;
				}
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		default:
			check(false); // Invalid state
			break;
		}
	} while( __CurrentState != -1 );
}
void APathGrid_C__pf2614143031::bpf__GetNeighbors__pf(APathTile_C__pf2614143031* bpp__Tile__pf, /*out*/ TArray<APathTile_C__pf2614143031*>& bpp__Neighbors__pf)
{
	TArray<FVector2D> bpfv__Possible__pf{};
	TArray<APathTile_C__pf2614143031*> bpfv__ValidNeighbors__pf{};
	int32 bpfv__Temp_int_Array_Index_Variable__pf{};
	int32 bpfv__Temp_int_Loop_Counter_Variable__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue__pf{};
	FVector2D bpfv__CallFunc_Array_Get_Item__pf(EForceInit::ForceInit);
	int32 bpfv__CallFunc_Array_Length_ReturnValue__pf{};
	FVector2D bpfv__CallFunc_Add_Vector2DVector2D_ReturnValue__pf(EForceInit::ForceInit);
	bool bpfv__CallFunc_Less_IntInt_ReturnValue__pf{};
	APathTile_C__pf2614143031* bpfv__CallFunc_Map_Find_Value__pf{};
	bool bpfv__CallFunc_Map_Find_ReturnValue__pf{};
	int32 bpfv__CallFunc_Array_AddUnique_ReturnValue__pf{};
	bool bpfv__CallFunc_EqualEqual_ByteByte_ReturnValue__pf{};
	TArray<FVector2D> bpfv__K2Node_MakeArray_Array__pf{};
	TArray< int32, TInlineAllocator<8> > __StateStack;

	int32 __CurrentState = 18;
	do
	{
		switch( __CurrentState )
		{
		case 18:
			{
			}
		case 1:
			{
				__StateStack.Push(2);
				__CurrentState = 12;
				break;
			}
		case 2:
			{
			}
		case 3:
			{
			}
		case 4:
			{
			}
		case 5:
			{
				bpfv__Temp_int_Loop_Counter_Variable__pf = 0;
			}
		case 6:
			{
				bpfv__Temp_int_Array_Index_Variable__pf = 0;
			}
		case 7:
			{
				bpfv__CallFunc_Array_Length_ReturnValue__pf = FCustomThunkTemplates::Array_Length(bpfv__Possible__pf);
				bpfv__CallFunc_Less_IntInt_ReturnValue__pf = UKismetMathLibrary::Less_IntInt(bpfv__Temp_int_Loop_Counter_Variable__pf, bpfv__CallFunc_Array_Length_ReturnValue__pf);
				if (!bpfv__CallFunc_Less_IntInt_ReturnValue__pf)
				{
					__CurrentState = 13;
					break;
				}
			}
		case 8:
			{
				bpfv__Temp_int_Array_Index_Variable__pf = bpfv__Temp_int_Loop_Counter_Variable__pf;
			}
		case 9:
			{
				__StateStack.Push(10);
				__CurrentState = 15;
				break;
			}
		case 10:
			{
			}
		case 11:
			{
				bpfv__CallFunc_Add_IntInt_ReturnValue__pf = UKismetMathLibrary::Add_IntInt(bpfv__Temp_int_Loop_Counter_Variable__pf, 1);
				bpfv__Temp_int_Loop_Counter_Variable__pf = bpfv__CallFunc_Add_IntInt_ReturnValue__pf;
				__CurrentState = 7;
				break;
			}
		case 12:
			{
				bpfv__K2Node_MakeArray_Array__pf.SetNum(7, true);
				bpfv__K2Node_MakeArray_Array__pf[0] = FVector2D(1.000000,0.000000);
				bpfv__K2Node_MakeArray_Array__pf[1] = FVector2D(1.000000,-1.000000);
				bpfv__K2Node_MakeArray_Array__pf[2] = FVector2D(0.000000,-1.000000);
				bpfv__K2Node_MakeArray_Array__pf[3] = FVector2D(-1.000000,-1.000000);
				bpfv__K2Node_MakeArray_Array__pf[4] = FVector2D(-1.000000,0.000000);
				bpfv__K2Node_MakeArray_Array__pf[5] = FVector2D(-1.000000,1.000000);
				bpfv__K2Node_MakeArray_Array__pf[6] = FVector2D(1.000000,1.000000);
				bpfv__Possible__pf = bpfv__K2Node_MakeArray_Array__pf;
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 13:
			{
			}
		case 14:
			{
				bpp__Neighbors__pf = bpfv__ValidNeighbors__pf;
				__CurrentState = -1;
				break;
			}
		case 15:
			{
			}
		case 16:
			{
				FCustomThunkTemplates::Array_Get(bpfv__Possible__pf, bpfv__Temp_int_Array_Index_Variable__pf, /*out*/ bpfv__CallFunc_Array_Get_Item__pf);
				FVector2D  __Local__7 = FVector2D(0.000000,0.000000);
				bpfv__CallFunc_Add_Vector2DVector2D_ReturnValue__pf = UKismetMathLibrary::Add_Vector2DVector2D(bpfv__CallFunc_Array_Get_Item__pf, ((::IsValid(bpp__Tile__pf)) ? (bpp__Tile__pf->bpv__Index__pf) : (__Local__7)));
				bpfv__CallFunc_Map_Find_ReturnValue__pf = FCustomThunkTemplates::Map_Find(bpv__TileData__pf, bpfv__CallFunc_Add_Vector2DVector2D_ReturnValue__pf, /*out*/ bpfv__CallFunc_Map_Find_Value__pf);
				E__PathTileTypes__pf  __Local__8 = E__PathTileTypes__pf::NewEnumerator1;
				bpfv__CallFunc_EqualEqual_ByteByte_ReturnValue__pf = UKismetMathLibrary::EqualEqual_ByteByte(static_cast<uint8>(((::IsValid(bpfv__CallFunc_Map_Find_Value__pf)) ? (bpfv__CallFunc_Map_Find_Value__pf->bpv__Type__pf) : (__Local__8))), static_cast<uint8>(E__PathTileTypes__pf::NewEnumerator1));
				if (!bpfv__CallFunc_EqualEqual_ByteByte_ReturnValue__pf)
				{
					__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
					break;
				}
			}
		case 17:
			{
				FCustomThunkTemplates::Array_Get(bpfv__Possible__pf, bpfv__Temp_int_Array_Index_Variable__pf, /*out*/ bpfv__CallFunc_Array_Get_Item__pf);
				FVector2D  __Local__9 = FVector2D(0.000000,0.000000);
				bpfv__CallFunc_Add_Vector2DVector2D_ReturnValue__pf = UKismetMathLibrary::Add_Vector2DVector2D(bpfv__CallFunc_Array_Get_Item__pf, ((::IsValid(bpp__Tile__pf)) ? (bpp__Tile__pf->bpv__Index__pf) : (__Local__9)));
				bpfv__CallFunc_Map_Find_ReturnValue__pf = FCustomThunkTemplates::Map_Find(bpv__TileData__pf, bpfv__CallFunc_Add_Vector2DVector2D_ReturnValue__pf, /*out*/ bpfv__CallFunc_Map_Find_Value__pf);
				bpfv__CallFunc_Array_AddUnique_ReturnValue__pf = FCustomThunkTemplates::Array_AddUnique(bpfv__ValidNeighbors__pf, bpfv__CallFunc_Map_Find_Value__pf);
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		default:
			check(false); // Invalid state
			break;
		}
	} while( __CurrentState != -1 );
}
void APathGrid_C__pf2614143031::bpf__CreateTiles__pf()
{
}
void APathGrid_C__pf2614143031::bpf__GetEstimatedCostToTarget__pf(FVector2D bpp__CurrentIndex__pf, FVector2D bpp__TargetIndex__pf, /*out*/ int32& bpp__Cost__pf)
{
	FVector2D bpfv__CallFunc_Subtract_Vector2DVector2D_ReturnValue__pf(EForceInit::ForceInit);
	float bpfv__CallFunc_BreakVector2D_X__pf{};
	float bpfv__CallFunc_BreakVector2D_Y__pf{};
	float bpfv__CallFunc_Abs_ReturnValue__pf{};
	float bpfv__CallFunc_Abs_ReturnValue_1__pf{};
	float bpfv__CallFunc_Add_FloatFloat_ReturnValue__pf{};
	int32 bpfv__CallFunc_Round_ReturnValue__pf{};
	bpfv__CallFunc_Subtract_Vector2DVector2D_ReturnValue__pf = UKismetMathLibrary::Subtract_Vector2DVector2D(bpp__CurrentIndex__pf, bpp__TargetIndex__pf);
	UKismetMathLibrary::BreakVector2D(bpfv__CallFunc_Subtract_Vector2DVector2D_ReturnValue__pf, /*out*/ bpfv__CallFunc_BreakVector2D_X__pf, /*out*/ bpfv__CallFunc_BreakVector2D_Y__pf);
	bpfv__CallFunc_Abs_ReturnValue__pf = UKismetMathLibrary::Abs(bpfv__CallFunc_BreakVector2D_X__pf);
	bpfv__CallFunc_Abs_ReturnValue_1__pf = UKismetMathLibrary::Abs(bpfv__CallFunc_BreakVector2D_Y__pf);
	bpfv__CallFunc_Add_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Add_FloatFloat(bpfv__CallFunc_Abs_ReturnValue__pf, bpfv__CallFunc_Abs_ReturnValue_1__pf);
	bpfv__CallFunc_Round_ReturnValue__pf = UKismetMathLibrary::Round(bpfv__CallFunc_Add_FloatFloat_ReturnValue__pf);
	bpp__Cost__pf = bpfv__CallFunc_Round_ReturnValue__pf;
}
void APathGrid_C__pf2614143031::bpf__GetDistance__pf(APathTile_C__pf2614143031* bpp__TileA__pf, APathTile_C__pf2614143031* bpp__TileB__pf, /*out*/ int32& bpp__Distance__pf)
{
	int32 bpfv__DistanceY__pf{};
	int32 bpfv__DistanceX__pf{};
	float bpfv__CallFunc_BreakVector2D_X__pf{};
	float bpfv__CallFunc_BreakVector2D_Y__pf{};
	float bpfv__CallFunc_BreakVector2D_X_1__pf{};
	float bpfv__CallFunc_BreakVector2D_Y_1__pf{};
	float bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf{};
	bool bpfv__CallFunc_Greater_IntInt_ReturnValue__pf{};
	float bpfv__CallFunc_Abs_ReturnValue__pf{};
	FString bpfv__CallFunc_Conv_BoolToString_ReturnValue__pf{};
	int32 bpfv__CallFunc_FTrunc_ReturnValue__pf{};
	float bpfv__CallFunc_Subtract_FloatFloat_ReturnValue_1__pf{};
	float bpfv__CallFunc_Abs_ReturnValue_1__pf{};
	int32 bpfv__CallFunc_FTrunc_ReturnValue_1__pf{};
	int32 bpfv__CallFunc_Multiply_IntInt_ReturnValue__pf{};
	int32 bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf{};
	int32 bpfv__CallFunc_Multiply_IntInt_ReturnValue_1__pf{};
	int32 bpfv__CallFunc_Subtract_IntInt_ReturnValue_1__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue__pf{};
	int32 bpfv__CallFunc_Multiply_IntInt_ReturnValue_2__pf{};
	int32 bpfv__CallFunc_Multiply_IntInt_ReturnValue_3__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf{};
	TArray< int32, TInlineAllocator<8> > __StateStack;

	int32 __CurrentState = 9;
	do
	{
		switch( __CurrentState )
		{
		case 9:
			{
			}
		case 1:
			{
				__StateStack.Push(2);
				__CurrentState = 6;
				break;
			}
		case 2:
			{
			}
		case 3:
			{
				bpfv__CallFunc_Greater_IntInt_ReturnValue__pf = UKismetMathLibrary::Greater_IntInt(bpfv__DistanceX__pf, bpfv__DistanceY__pf);
				bpfv__CallFunc_Conv_BoolToString_ReturnValue__pf = UKismetStringLibrary::Conv_BoolToString(bpfv__CallFunc_Greater_IntInt_ReturnValue__pf);
				UKismetSystemLibrary::PrintString(this, bpfv__CallFunc_Conv_BoolToString_ReturnValue__pf, true, true, FLinearColor(0.000000,0.660000,1.000000,1.000000), 2.000000);
			}
		case 4:
			{
				bpfv__CallFunc_Greater_IntInt_ReturnValue__pf = UKismetMathLibrary::Greater_IntInt(bpfv__DistanceX__pf, bpfv__DistanceY__pf);
				if (!bpfv__CallFunc_Greater_IntInt_ReturnValue__pf)
				{
					__CurrentState = 8;
					break;
				}
			}
		case 5:
			{
				bpfv__CallFunc_Subtract_IntInt_ReturnValue_1__pf = UKismetMathLibrary::Subtract_IntInt(bpfv__DistanceX__pf, bpfv__DistanceY__pf);
				bpfv__CallFunc_Multiply_IntInt_ReturnValue_2__pf = UKismetMathLibrary::Multiply_IntInt(bpfv__CallFunc_Subtract_IntInt_ReturnValue_1__pf, 10);
				bpfv__CallFunc_Multiply_IntInt_ReturnValue_3__pf = UKismetMathLibrary::Multiply_IntInt(bpfv__DistanceY__pf, 14);
				bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf = UKismetMathLibrary::Add_IntInt(bpfv__CallFunc_Multiply_IntInt_ReturnValue_3__pf, bpfv__CallFunc_Multiply_IntInt_ReturnValue_2__pf);
				bpp__Distance__pf = bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf;
				__CurrentState = -1;
				break;
			}
		case 6:
			{
				FVector2D  __Local__10 = FVector2D(0.000000,0.000000);
				UKismetMathLibrary::BreakVector2D(((::IsValid(bpp__TileB__pf)) ? (bpp__TileB__pf->bpv__Index__pf) : (__Local__10)), /*out*/ bpfv__CallFunc_BreakVector2D_X__pf, /*out*/ bpfv__CallFunc_BreakVector2D_Y__pf);
				FVector2D  __Local__11 = FVector2D(0.000000,0.000000);
				UKismetMathLibrary::BreakVector2D(((::IsValid(bpp__TileA__pf)) ? (bpp__TileA__pf->bpv__Index__pf) : (__Local__11)), /*out*/ bpfv__CallFunc_BreakVector2D_X_1__pf, /*out*/ bpfv__CallFunc_BreakVector2D_Y_1__pf);
				bpfv__CallFunc_Subtract_FloatFloat_ReturnValue_1__pf = UKismetMathLibrary::Subtract_FloatFloat(bpfv__CallFunc_BreakVector2D_X_1__pf, bpfv__CallFunc_BreakVector2D_X__pf);
				bpfv__CallFunc_Abs_ReturnValue_1__pf = UKismetMathLibrary::Abs(bpfv__CallFunc_Subtract_FloatFloat_ReturnValue_1__pf);
				bpfv__CallFunc_FTrunc_ReturnValue_1__pf = UKismetMathLibrary::FTrunc(bpfv__CallFunc_Abs_ReturnValue_1__pf);
				bpfv__DistanceX__pf = bpfv__CallFunc_FTrunc_ReturnValue_1__pf;
			}
		case 7:
			{
				FVector2D  __Local__12 = FVector2D(0.000000,0.000000);
				UKismetMathLibrary::BreakVector2D(((::IsValid(bpp__TileB__pf)) ? (bpp__TileB__pf->bpv__Index__pf) : (__Local__12)), /*out*/ bpfv__CallFunc_BreakVector2D_X__pf, /*out*/ bpfv__CallFunc_BreakVector2D_Y__pf);
				FVector2D  __Local__13 = FVector2D(0.000000,0.000000);
				UKismetMathLibrary::BreakVector2D(((::IsValid(bpp__TileA__pf)) ? (bpp__TileA__pf->bpv__Index__pf) : (__Local__13)), /*out*/ bpfv__CallFunc_BreakVector2D_X_1__pf, /*out*/ bpfv__CallFunc_BreakVector2D_Y_1__pf);
				bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Subtract_FloatFloat(bpfv__CallFunc_BreakVector2D_Y_1__pf, bpfv__CallFunc_BreakVector2D_Y__pf);
				bpfv__CallFunc_Abs_ReturnValue__pf = UKismetMathLibrary::Abs(bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf);
				bpfv__CallFunc_FTrunc_ReturnValue__pf = UKismetMathLibrary::FTrunc(bpfv__CallFunc_Abs_ReturnValue__pf);
				bpfv__DistanceY__pf = bpfv__CallFunc_FTrunc_ReturnValue__pf;
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 8:
			{
				bpfv__CallFunc_Multiply_IntInt_ReturnValue__pf = UKismetMathLibrary::Multiply_IntInt(bpfv__DistanceX__pf, 14);
				bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf = UKismetMathLibrary::Subtract_IntInt(bpfv__DistanceY__pf, bpfv__DistanceX__pf);
				bpfv__CallFunc_Multiply_IntInt_ReturnValue_1__pf = UKismetMathLibrary::Multiply_IntInt(bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf, 10);
				bpfv__CallFunc_Add_IntInt_ReturnValue__pf = UKismetMathLibrary::Add_IntInt(bpfv__CallFunc_Multiply_IntInt_ReturnValue__pf, bpfv__CallFunc_Multiply_IntInt_ReturnValue_1__pf);
				bpp__Distance__pf = bpfv__CallFunc_Add_IntInt_ReturnValue__pf;
				__CurrentState = -1;
				break;
			}
		default:
			check(false); // Invalid state
			break;
		}
	} while( __CurrentState != -1 );
}
void APathGrid_C__pf2614143031::bpf__GetTileFromIndex__pf(FVector2D const& bpp__Index__pf__const, /*out*/ APathTile_C__pf2614143031*& bpp__Tile__pf)
{
	typedef FVector2D  T__Local__14;
	T__Local__14& bpp__Index__pf = *const_cast<T__Local__14 *>(&bpp__Index__pf__const);
	APathTile_C__pf2614143031* bpfv__CallFunc_Map_Find_Value__pf{};
	bool bpfv__CallFunc_Map_Find_ReturnValue__pf{};
	bpfv__CallFunc_Map_Find_ReturnValue__pf = FCustomThunkTemplates::Map_Find(bpv__TileData__pf, bpp__Index__pf, /*out*/ bpfv__CallFunc_Map_Find_Value__pf);
	bpp__Tile__pf = bpfv__CallFunc_Map_Find_Value__pf;
}
void APathGrid_C__pf2614143031::bpf__FindPathToTarget__pf(APathTile_C__pf2614143031* bpp__Start__pf, APathTile_C__pf2614143031* bpp__Target__pf)
{
	int32 bpfv__CostToNeighbor__pf{};
	TArray<APathTile_C__pf2614143031*> bpfv__ClosedSet__pf{};
	TArray<APathTile_C__pf2614143031*> bpfv__OpenSet__pf{};
	APathTile_C__pf2614143031* bpfv__Neighbor__pf{};
	APathTile_C__pf2614143031* bpfv__Cheapest__pf{};
	APathTile_C__pf2614143031* bpfv__CurrentIndex__pf{};
	APathTile_C__pf2614143031* bpfv__TargetIndex__pf{};
	APathTile_C__pf2614143031* bpfv__StartIndex__pf{};
	int32 bpfv__Temp_int_Loop_Counter_Variable__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue__pf{};
	int32 bpfv__Temp_int_Array_Index_Variable__pf{};
	int32 bpfv__Temp_int_Loop_Counter_Variable_1__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf{};
	int32 bpfv__Temp_int_Array_Index_Variable_1__pf{};
	bool bpfv__CallFunc_EqualEqual_ObjectObject_ReturnValue__pf{};
	int32 bpfv__CallFunc_Array_AddUnique_ReturnValue__pf{};
	bool bpfv__CallFunc_Array_Contains_ReturnValue__pf{};
	bool bpfv__CallFunc_Not_PreBool_ReturnValue__pf{};
	int32 bpfv__CallFunc_GetDistance_Distance__pf{};
	bool bpfv__CallFunc_Array_Contains_ReturnValue_1__pf{};
	bool bpfv__CallFunc_Not_PreBool_ReturnValue_1__pf{};
	int32 bpfv__CallFunc_GetDistance_Distance_1__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue_2__pf{};
	bool bpfv__CallFunc_Array_Contains_ReturnValue_2__pf{};
	bool bpfv__CallFunc_Not_PreBool_ReturnValue_2__pf{};
	bool bpfv__CallFunc_Less_IntInt_ReturnValue__pf{};
	bool bpfv__CallFunc_BooleanOR_ReturnValue__pf{};
	TArray<APathTile_C__pf2614143031*> bpfv__CallFunc_GetNeighbors_Neighbors__pf{};
	APathTile_C__pf2614143031* bpfv__CallFunc_Array_Get_Item__pf{};
	int32 bpfv__CallFunc_Array_Length_ReturnValue__pf{};
	bool bpfv__CallFunc_Less_IntInt_ReturnValue_1__pf{};
	int32 bpfv__CallFunc_Array_AddUnique_ReturnValue_1__pf{};
	bool bpfv__CallFunc_Array_RemoveItem_ReturnValue__pf{};
	APathTile_C__pf2614143031* bpfv__CallFunc_Array_Get_Item_1__pf{};
	APathTile_C__pf2614143031* bpfv__CallFunc_Array_Get_Item_2__pf{};
	int32 bpfv__CallFunc_Array_Length_ReturnValue_1__pf{};
	bool bpfv__CallFunc_Less_IntInt_ReturnValue_2__pf{};
	bool bpfv__CallFunc_Less_IntInt_ReturnValue_3__pf{};
	int32 bpfv__CallFunc_Array_Length_ReturnValue_2__pf{};
	bool bpfv__CallFunc_Greater_IntInt_ReturnValue__pf{};
	int32 bpfv__CallFunc_Array_AddUnique_ReturnValue_2__pf{};
	TArray< int32, TInlineAllocator<8> > __StateStack;

	int32 __CurrentState = 54;
	do
	{
		switch( __CurrentState )
		{
		case 54:
			{
			}
		case 1:
			{
				bpf__ClearxPath__pfT();
			}
		case 2:
			{
				bpfv__StartIndex__pf = bpp__Start__pf;
			}
		case 3:
			{
				bpfv__TargetIndex__pf = bpp__Target__pf;
			}
		case 4:
			{
				bpfv__CurrentIndex__pf = bpfv__StartIndex__pf;
			}
		case 5:
			{
				bpfv__CallFunc_Array_AddUnique_ReturnValue_2__pf = FCustomThunkTemplates::Array_AddUnique(bpfv__OpenSet__pf, bpfv__StartIndex__pf);
			}
		case 6:
			{
			}
		case 7:
			{
			}
		case 8:
			{
				bpfv__CallFunc_Array_Length_ReturnValue_2__pf = FCustomThunkTemplates::Array_Length(bpfv__OpenSet__pf);
				bpfv__CallFunc_Greater_IntInt_ReturnValue__pf = UKismetMathLibrary::Greater_IntInt(bpfv__CallFunc_Array_Length_ReturnValue_2__pf, 0);
				if (!bpfv__CallFunc_Greater_IntInt_ReturnValue__pf)
				{
					__CurrentState = 11;
					break;
				}
			}
		case 9:
			{
				__StateStack.Push(10);
				__CurrentState = 13;
				break;
			}
		case 10:
			{
				__CurrentState = 8;
				break;
			}
		case 11:
			{
			}
		case 12:
			{
				__CurrentState = -1;
				break;
			}
		case 13:
			{
			}
		case 14:
			{
				FCustomThunkTemplates::Array_Get(bpfv__OpenSet__pf, 0, /*out*/ bpfv__CallFunc_Array_Get_Item_1__pf);
				bpfv__Cheapest__pf = bpfv__CallFunc_Array_Get_Item_1__pf;
			}
		case 15:
			{
			}
		case 16:
			{
			}
		case 17:
			{
				bpfv__Temp_int_Loop_Counter_Variable__pf = 0;
			}
		case 18:
			{
				bpfv__Temp_int_Array_Index_Variable__pf = 0;
			}
		case 19:
			{
				bpfv__CallFunc_Array_Length_ReturnValue_1__pf = FCustomThunkTemplates::Array_Length(bpfv__OpenSet__pf);
				bpfv__CallFunc_Less_IntInt_ReturnValue_2__pf = UKismetMathLibrary::Less_IntInt(bpfv__Temp_int_Loop_Counter_Variable__pf, bpfv__CallFunc_Array_Length_ReturnValue_1__pf);
				if (!bpfv__CallFunc_Less_IntInt_ReturnValue_2__pf)
				{
					__CurrentState = 27;
					break;
				}
			}
		case 20:
			{
				bpfv__Temp_int_Array_Index_Variable__pf = bpfv__Temp_int_Loop_Counter_Variable__pf;
			}
		case 21:
			{
				__StateStack.Push(22);
				__CurrentState = 24;
				break;
			}
		case 22:
			{
			}
		case 23:
			{
				bpfv__CallFunc_Add_IntInt_ReturnValue__pf = UKismetMathLibrary::Add_IntInt(bpfv__Temp_int_Loop_Counter_Variable__pf, 1);
				bpfv__Temp_int_Loop_Counter_Variable__pf = bpfv__CallFunc_Add_IntInt_ReturnValue__pf;
				__CurrentState = 19;
				break;
			}
		case 24:
			{
			}
		case 25:
			{
				FCustomThunkTemplates::Array_Get(bpfv__OpenSet__pf, bpfv__Temp_int_Array_Index_Variable__pf, /*out*/ bpfv__CallFunc_Array_Get_Item_2__pf);
				int32  __Local__15 = 0;
				int32  __Local__16 = 0;
				bpfv__CallFunc_Less_IntInt_ReturnValue_3__pf = UKismetMathLibrary::Less_IntInt(((::IsValid(bpfv__CallFunc_Array_Get_Item_2__pf)) ? (bpfv__CallFunc_Array_Get_Item_2__pf->bpv__HCost__pf) : (__Local__15)), ((::IsValid(bpfv__Cheapest__pf)) ? (bpfv__Cheapest__pf->bpv__HCost__pf) : (__Local__16)));
				if (!bpfv__CallFunc_Less_IntInt_ReturnValue_3__pf)
				{
					__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
					break;
				}
			}
		case 26:
			{
				FCustomThunkTemplates::Array_Get(bpfv__OpenSet__pf, bpfv__Temp_int_Array_Index_Variable__pf, /*out*/ bpfv__CallFunc_Array_Get_Item_2__pf);
				bpfv__Cheapest__pf = bpfv__CallFunc_Array_Get_Item_2__pf;
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 27:
			{
			}
		case 28:
			{
				bpfv__CurrentIndex__pf = bpfv__Cheapest__pf;
			}
		case 29:
			{
				bpfv__CallFunc_Array_RemoveItem_ReturnValue__pf = FCustomThunkTemplates::Array_RemoveItem(bpfv__OpenSet__pf, bpfv__CurrentIndex__pf);
			}
		case 30:
			{
				bpfv__CallFunc_Array_AddUnique_ReturnValue_1__pf = FCustomThunkTemplates::Array_AddUnique(bpfv__ClosedSet__pf, bpfv__CurrentIndex__pf);
			}
		case 31:
			{
				bpfv__CallFunc_EqualEqual_ObjectObject_ReturnValue__pf = UKismetMathLibrary::EqualEqual_ObjectObject(bpfv__CurrentIndex__pf, bpfv__TargetIndex__pf);
				if (!bpfv__CallFunc_EqualEqual_ObjectObject_ReturnValue__pf)
				{
					__CurrentState = 34;
					break;
				}
			}
		case 32:
			{
				bpf__RetracePath__pf(bpfv__TargetIndex__pf, bpfv__StartIndex__pf);
			}
		case 33:
			{
				__CurrentState = -1;
				break;
			}
		case 34:
			{
			}
		case 35:
			{
			}
		case 36:
			{
				bpfv__Temp_int_Loop_Counter_Variable_1__pf = 0;
			}
		case 37:
			{
				bpfv__Temp_int_Array_Index_Variable_1__pf = 0;
			}
		case 38:
			{
				bpf__GetNeighbors__pf(bpfv__CurrentIndex__pf, /*out*/ bpfv__CallFunc_GetNeighbors_Neighbors__pf);
				bpfv__CallFunc_Array_Length_ReturnValue__pf = FCustomThunkTemplates::Array_Length(bpfv__CallFunc_GetNeighbors_Neighbors__pf);
				bpfv__CallFunc_Less_IntInt_ReturnValue_1__pf = UKismetMathLibrary::Less_IntInt(bpfv__Temp_int_Loop_Counter_Variable_1__pf, bpfv__CallFunc_Array_Length_ReturnValue__pf);
				if (!bpfv__CallFunc_Less_IntInt_ReturnValue_1__pf)
				{
					__CurrentState = 53;
					break;
				}
			}
		case 39:
			{
				bpfv__Temp_int_Array_Index_Variable_1__pf = bpfv__Temp_int_Loop_Counter_Variable_1__pf;
			}
		case 40:
			{
				__StateStack.Push(41);
				__CurrentState = 43;
				break;
			}
		case 41:
			{
			}
		case 42:
			{
				bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf = UKismetMathLibrary::Add_IntInt(bpfv__Temp_int_Loop_Counter_Variable_1__pf, 1);
				bpfv__Temp_int_Loop_Counter_Variable_1__pf = bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf;
				__CurrentState = 38;
				break;
			}
		case 43:
			{
			}
		case 44:
			{
				bpf__GetNeighbors__pf(bpfv__CurrentIndex__pf, /*out*/ bpfv__CallFunc_GetNeighbors_Neighbors__pf);
				FCustomThunkTemplates::Array_Get(bpfv__CallFunc_GetNeighbors_Neighbors__pf, bpfv__Temp_int_Array_Index_Variable_1__pf, /*out*/ bpfv__CallFunc_Array_Get_Item__pf);
				bpfv__Neighbor__pf = bpfv__CallFunc_Array_Get_Item__pf;
			}
		case 45:
			{
				bpfv__CallFunc_Array_Contains_ReturnValue_2__pf = FCustomThunkTemplates::Array_Contains(bpfv__ClosedSet__pf, bpfv__Neighbor__pf);
				bpfv__CallFunc_Not_PreBool_ReturnValue_2__pf = UKismetMathLibrary::Not_PreBool(bpfv__CallFunc_Array_Contains_ReturnValue_2__pf);
				if (!bpfv__CallFunc_Not_PreBool_ReturnValue_2__pf)
				{
					__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
					break;
				}
			}
		case 46:
			{
				bpf__GetDistance__pf(bpfv__CurrentIndex__pf, bpfv__Neighbor__pf, /*out*/ bpfv__CallFunc_GetDistance_Distance_1__pf);
				int32  __Local__17 = 0;
				bpfv__CallFunc_Add_IntInt_ReturnValue_2__pf = UKismetMathLibrary::Add_IntInt(((::IsValid(bpfv__CurrentIndex__pf)) ? (bpfv__CurrentIndex__pf->bpv__GCost__pf) : (__Local__17)), bpfv__CallFunc_GetDistance_Distance_1__pf);
				bpfv__CostToNeighbor__pf = bpfv__CallFunc_Add_IntInt_ReturnValue_2__pf;
			}
		case 47:
			{
				bpfv__CallFunc_Array_Contains_ReturnValue_1__pf = FCustomThunkTemplates::Array_Contains(bpfv__OpenSet__pf, bpfv__Neighbor__pf);
				bpfv__CallFunc_Not_PreBool_ReturnValue_1__pf = UKismetMathLibrary::Not_PreBool(bpfv__CallFunc_Array_Contains_ReturnValue_1__pf);
				bpf__GetDistance__pf(bpfv__CurrentIndex__pf, bpfv__Neighbor__pf, /*out*/ bpfv__CallFunc_GetDistance_Distance_1__pf);
				int32  __Local__18 = 0;
				bpfv__CallFunc_Add_IntInt_ReturnValue_2__pf = UKismetMathLibrary::Add_IntInt(((::IsValid(bpfv__CurrentIndex__pf)) ? (bpfv__CurrentIndex__pf->bpv__GCost__pf) : (__Local__18)), bpfv__CallFunc_GetDistance_Distance_1__pf);
				int32  __Local__19 = 0;
				bpfv__CallFunc_Less_IntInt_ReturnValue__pf = UKismetMathLibrary::Less_IntInt(bpfv__CallFunc_Add_IntInt_ReturnValue_2__pf, ((::IsValid(bpfv__Neighbor__pf)) ? (bpfv__Neighbor__pf->bpv__GCost__pf) : (__Local__19)));
				bpfv__CallFunc_BooleanOR_ReturnValue__pf = UKismetMathLibrary::BooleanOR(bpfv__CallFunc_Not_PreBool_ReturnValue_1__pf, bpfv__CallFunc_Less_IntInt_ReturnValue__pf);
				if (!bpfv__CallFunc_BooleanOR_ReturnValue__pf)
				{
					__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
					break;
				}
			}
		case 48:
			{
				if(::IsValid(bpfv__Neighbor__pf))
				{
					bpfv__Neighbor__pf->bpv__GCost__pf = bpfv__CostToNeighbor__pf;
				}
			}
		case 49:
			{
				bpf__GetDistance__pf(bpfv__Neighbor__pf, bpfv__TargetIndex__pf, /*out*/ bpfv__CallFunc_GetDistance_Distance__pf);
				if(::IsValid(bpfv__Neighbor__pf))
				{
					bpfv__Neighbor__pf->bpv__HCost__pf = bpfv__CallFunc_GetDistance_Distance__pf;
				}
			}
		case 50:
			{
				if(::IsValid(bpfv__Neighbor__pf))
				{
					bpfv__Neighbor__pf->bpv__PreviousTile__pf = bpfv__CurrentIndex__pf;
				}
			}
		case 51:
			{
				bpfv__CallFunc_Array_Contains_ReturnValue__pf = FCustomThunkTemplates::Array_Contains(bpfv__OpenSet__pf, bpfv__Neighbor__pf);
				bpfv__CallFunc_Not_PreBool_ReturnValue__pf = UKismetMathLibrary::Not_PreBool(bpfv__CallFunc_Array_Contains_ReturnValue__pf);
				if (!bpfv__CallFunc_Not_PreBool_ReturnValue__pf)
				{
					__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
					break;
				}
			}
		case 52:
			{
				bpfv__CallFunc_Array_AddUnique_ReturnValue__pf = FCustomThunkTemplates::Array_AddUnique(bpfv__OpenSet__pf, bpfv__Neighbor__pf);
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 53:
			{
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		default:
			check(false); // Invalid state
			break;
		}
	} while( __CurrentState != -1 );
}
void APathGrid_C__pf2614143031::bpf__RetracePath__pf(APathTile_C__pf2614143031* bpp__Target__pf, APathTile_C__pf2614143031* bpp__Start__pf)
{
	TArray<APathTile_C__pf2614143031*> bpfv__OutPath__pf{};
	TArray<APathTile_C__pf2614143031*> bpfv__ReversedPath__pf{};
	APathTile_C__pf2614143031* bpfv__CurrentTile__pf{};
	int32 bpfv__Temp_int_Loop_Counter_Variable__pf{};
	int32 bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf{};
	bool bpfv__CallFunc_GreaterEqual_IntInt_ReturnValue__pf{};
	int32 bpfv__Temp_int_Array_Index_Variable__pf{};
	bool bpfv__CallFunc_EqualEqual_ObjectObject_ReturnValue__pf{};
	bool bpfv__CallFunc_Not_PreBool_ReturnValue__pf{};
	APathTile_C__pf2614143031* bpfv__CallFunc_Array_Get_Item__pf{};
	int32 bpfv__CallFunc_Array_Length_ReturnValue__pf{};
	int32 bpfv__CallFunc_Subtract_IntInt_ReturnValue_1__pf{};
	int32 bpfv__CallFunc_Array_AddUnique_ReturnValue__pf{};
	int32 bpfv__CallFunc_Max_ReturnValue__pf{};
	int32 bpfv__CallFunc_Array_AddUnique_ReturnValue_1__pf{};
	TArray< int32, TInlineAllocator<8> > __StateStack;

	int32 __CurrentState = 25;
	do
	{
		switch( __CurrentState )
		{
		case 25:
			{
			}
		case 1:
			{
				bpfv__CurrentTile__pf = bpp__Target__pf;
			}
		case 2:
			{
			}
		case 3:
			{
			}
		case 4:
			{
				bpfv__CallFunc_EqualEqual_ObjectObject_ReturnValue__pf = UKismetMathLibrary::EqualEqual_ObjectObject(bpfv__CurrentTile__pf, bpp__Start__pf);
				bpfv__CallFunc_Not_PreBool_ReturnValue__pf = UKismetMathLibrary::Not_PreBool(bpfv__CallFunc_EqualEqual_ObjectObject_ReturnValue__pf);
				if (!bpfv__CallFunc_Not_PreBool_ReturnValue__pf)
				{
					__CurrentState = 7;
					break;
				}
			}
		case 5:
			{
				__StateStack.Push(6);
				__CurrentState = 19;
				break;
			}
		case 6:
			{
				__CurrentState = 4;
				break;
			}
		case 7:
			{
			}
		case 8:
			{
			}
		case 9:
			{
			}
		case 10:
			{
				bpfv__CallFunc_Array_Length_ReturnValue__pf = FCustomThunkTemplates::Array_Length(bpfv__ReversedPath__pf);
				bpfv__CallFunc_Subtract_IntInt_ReturnValue_1__pf = UKismetMathLibrary::Subtract_IntInt(bpfv__CallFunc_Array_Length_ReturnValue__pf, 1);
				bpfv__Temp_int_Loop_Counter_Variable__pf = bpfv__CallFunc_Subtract_IntInt_ReturnValue_1__pf;
			}
		case 11:
			{
				bpfv__CallFunc_Array_Length_ReturnValue__pf = FCustomThunkTemplates::Array_Length(bpfv__ReversedPath__pf);
				bpfv__CallFunc_Subtract_IntInt_ReturnValue_1__pf = UKismetMathLibrary::Subtract_IntInt(bpfv__CallFunc_Array_Length_ReturnValue__pf, 1);
				bpfv__CallFunc_Max_ReturnValue__pf = UKismetMathLibrary::Max(0, bpfv__CallFunc_Subtract_IntInt_ReturnValue_1__pf);
				bpfv__Temp_int_Array_Index_Variable__pf = bpfv__CallFunc_Max_ReturnValue__pf;
			}
		case 12:
			{
				bpfv__CallFunc_GreaterEqual_IntInt_ReturnValue__pf = UKismetMathLibrary::GreaterEqual_IntInt(bpfv__Temp_int_Loop_Counter_Variable__pf, 0);
				if (!bpfv__CallFunc_GreaterEqual_IntInt_ReturnValue__pf)
				{
					__CurrentState = 17;
					break;
				}
			}
		case 13:
			{
				bpfv__Temp_int_Array_Index_Variable__pf = bpfv__Temp_int_Loop_Counter_Variable__pf;
			}
		case 14:
			{
				__StateStack.Push(15);
				__CurrentState = 22;
				break;
			}
		case 15:
			{
			}
		case 16:
			{
				bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf = UKismetMathLibrary::Subtract_IntInt(bpfv__Temp_int_Loop_Counter_Variable__pf, 1);
				bpfv__Temp_int_Loop_Counter_Variable__pf = bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf;
				__CurrentState = 12;
				break;
			}
		case 17:
			{
			}
		case 18:
			{
				bpv__Path___pf = bpfv__OutPath__pf;
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 19:
			{
			}
		case 20:
			{
				bpfv__CallFunc_Array_AddUnique_ReturnValue_1__pf = FCustomThunkTemplates::Array_AddUnique(bpfv__ReversedPath__pf, bpfv__CurrentTile__pf);
			}
		case 21:
			{
				APathTile_C__pf2614143031*  __Local__20 = ((APathTile_C__pf2614143031*)nullptr);
				bpfv__CurrentTile__pf = ((::IsValid(bpfv__CurrentTile__pf)) ? (bpfv__CurrentTile__pf->bpv__PreviousTile__pf) : (__Local__20));
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 22:
			{
			}
		case 23:
			{
				FCustomThunkTemplates::Array_Get(bpfv__ReversedPath__pf, bpfv__Temp_int_Array_Index_Variable__pf, /*out*/ bpfv__CallFunc_Array_Get_Item__pf);
				if(::IsValid(bpfv__CallFunc_Array_Get_Item__pf))
				{
					bpfv__CallFunc_Array_Get_Item__pf->bpv__IsxinxPath__pfTT = true;
				}
			}
		case 24:
			{
				FCustomThunkTemplates::Array_Get(bpfv__ReversedPath__pf, bpfv__Temp_int_Array_Index_Variable__pf, /*out*/ bpfv__CallFunc_Array_Get_Item__pf);
				bpfv__CallFunc_Array_AddUnique_ReturnValue__pf = FCustomThunkTemplates::Array_AddUnique(bpfv__OutPath__pf, bpfv__CallFunc_Array_Get_Item__pf);
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		default:
			check(false); // Invalid state
			break;
		}
	} while( __CurrentState != -1 );
}
void APathGrid_C__pf2614143031::bpf__ClearxPath__pfT()
{
	int32 bpfv__Temp_int_Loop_Counter_Variable__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue__pf{};
	int32 bpfv__Temp_int_Array_Index_Variable__pf{};
	TArray<APathTile_C__pf2614143031*> bpfv__CallFunc_Map_Values_Values__pf{};
	int32 bpfv__CallFunc_Array_Length_ReturnValue__pf{};
	APathTile_C__pf2614143031* bpfv__CallFunc_Array_Get_Item__pf{};
	bool bpfv__CallFunc_Less_IntInt_ReturnValue__pf{};
	TArray< int32, TInlineAllocator<8> > __StateStack;

	int32 __CurrentState = 14;
	do
	{
		switch( __CurrentState )
		{
		case 14:
			{
			}
		case 1:
			{
				(bpfv__CallFunc_Map_Values_Values__pf).Reset();
				FCustomThunkTemplates::Map_Values(bpv__TileData__pf, /*out*/ bpfv__CallFunc_Map_Values_Values__pf);
			}
		case 2:
			{
			}
		case 3:
			{
			}
		case 4:
			{
				bpfv__Temp_int_Loop_Counter_Variable__pf = 0;
			}
		case 5:
			{
				bpfv__Temp_int_Array_Index_Variable__pf = 0;
			}
		case 6:
			{
				bpfv__CallFunc_Array_Length_ReturnValue__pf = FCustomThunkTemplates::Array_Length(bpfv__CallFunc_Map_Values_Values__pf);
				bpfv__CallFunc_Less_IntInt_ReturnValue__pf = UKismetMathLibrary::Less_IntInt(bpfv__Temp_int_Loop_Counter_Variable__pf, bpfv__CallFunc_Array_Length_ReturnValue__pf);
				if (!bpfv__CallFunc_Less_IntInt_ReturnValue__pf)
				{
					__CurrentState = 11;
					break;
				}
			}
		case 7:
			{
				bpfv__Temp_int_Array_Index_Variable__pf = bpfv__Temp_int_Loop_Counter_Variable__pf;
			}
		case 8:
			{
				__StateStack.Push(9);
				__CurrentState = 12;
				break;
			}
		case 9:
			{
			}
		case 10:
			{
				bpfv__CallFunc_Add_IntInt_ReturnValue__pf = UKismetMathLibrary::Add_IntInt(bpfv__Temp_int_Loop_Counter_Variable__pf, 1);
				bpfv__Temp_int_Loop_Counter_Variable__pf = bpfv__CallFunc_Add_IntInt_ReturnValue__pf;
				__CurrentState = 6;
				break;
			}
		case 11:
			{
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 12:
			{
			}
		case 13:
			{
				FCustomThunkTemplates::Array_Get(bpfv__CallFunc_Map_Values_Values__pf, bpfv__Temp_int_Array_Index_Variable__pf, /*out*/ bpfv__CallFunc_Array_Get_Item__pf);
				if(::IsValid(bpfv__CallFunc_Array_Get_Item__pf))
				{
					bpfv__CallFunc_Array_Get_Item__pf->bpf__SetColor__pf();
				}
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		default:
			check(false); // Invalid state
			break;
		}
	} while( __CurrentState != -1 );
}
PRAGMA_DISABLE_OPTIMIZATION
void APathGrid_C__pf2614143031::__StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	const FCompactBlueprintDependencyData LocCompactBlueprintDependencyData[] =
	{
		{0, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Texture2D /Engine/Functions/Engine_MaterialFunctions01/Debug/T_Grid.T_Grid 
	};
	for(const FCompactBlueprintDependencyData& CompactData : LocCompactBlueprintDependencyData)
	{
		AssetsToLoad.Add(FBlueprintDependencyData(F__NativeDependencies::Get(CompactData.ObjectRefIndex), CompactData));
	}
}
PRAGMA_ENABLE_OPTIMIZATION
PRAGMA_DISABLE_OPTIMIZATION
void APathGrid_C__pf2614143031::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_DirectlyUsedAssets(AssetsToLoad);
	const FCompactBlueprintDependencyData LocCompactBlueprintDependencyData[] =
	{
		{1, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.SceneComponent 
		{2, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.BillboardComponent 
		{3, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetSystemLibrary 
		{4, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetMathLibrary 
		{5, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.Actor 
		{6, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.BlueprintMapLibrary 
		{7, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetArrayLibrary 
		{8, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetStringLibrary 
		{9, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.GameplayStatics 
		{10, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Enum /Script/Engine.ETraceTypeQuery 
		{11, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.HitResult 
		{12, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.PointerToUberGraphFrame 
		{13, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.StaticMeshComponent 
		{14, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  StaticMesh /Game/Geometry/Meshes/Tile.Tile 
		{15, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.PrimitiveComponent 
		{16, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/InputCore.Key 
		{17, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.LatentActionInfo 
		{18, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.MeshComponent 
		{19, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  BlueprintGeneratedClass /Game/Blueprints/Pathfinding/PathTile.PathTile_C 
		{20, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  UserDefinedEnum /Game/Blueprints/Pathfinding/PathTileTypes.PathTileTypes 
	};
	for(const FCompactBlueprintDependencyData& CompactData : LocCompactBlueprintDependencyData)
	{
		AssetsToLoad.Add(FBlueprintDependencyData(F__NativeDependencies::Get(CompactData.ObjectRefIndex), CompactData));
	}
}
PRAGMA_ENABLE_OPTIMIZATION
struct FRegisterHelper__APathGrid_C__pf2614143031
{
	FRegisterHelper__APathGrid_C__pf2614143031()
	{
		FConvertedBlueprintsDependencies::Get().RegisterConvertedClass(TEXT("/Game/Blueprints/Pathfinding/PathGrid"), &APathGrid_C__pf2614143031::__StaticDependenciesAssets);
	}
	static FRegisterHelper__APathGrid_C__pf2614143031 Instance;
};
FRegisterHelper__APathGrid_C__pf2614143031 FRegisterHelper__APathGrid_C__pf2614143031::Instance;
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
