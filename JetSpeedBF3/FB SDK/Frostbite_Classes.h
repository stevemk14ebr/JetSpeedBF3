#ifndef __FROSTBITE_CLASSES_H__
#define __FROSTBITE_CLASSES_H__

namespace fb
{
	template< typename T > class WeakPtr;
	template< typename T > class Array;
	template< typename T > class RefArray;
	template< typename T > class RelocArray;
	template< typename T > class SmartRef;
	template< typename T > class SmartPtr;
	template< typename T > class ScopedPtr;
	template< typename T > class Tuple2;
	template< typename T > struct KindOfEntityIterator;
	//network
	namespace network
	{
		class Ghost;
		class ClientGhost;
		class IControlObjectState;
		class ServerGhost;
		class ICryptoKey;
		class ICrypto;
		class IChallengeMemento;
		class SecureConnection;
		class Secure;
		class Packet;
		class PacketBuffer;
		class PacketNotification;
		class IPacketStatusNotification;
		class ConnectionManager;
		class Connection;
		class EngineConnection;
		class IScopeFetcher;
		class IGhostCreator;
		class EngineConnectionPeer;
		class IChatMessageHandler;
		class EnginePeer;
		class ServerGhostFilter;
		class Ghost;
		class IControlObject;
		class IControlObjectClient;
		class IServerNetworkable;
		class InterpolationObject;
		class INetworkable;
		class IClientNetworkable;
		class IClientNetworkableGroupMember;
		class ClientNetworkableGroup;

		template <typename T> class Interpolator;
	};

	namespace online
	{
		class ClientConnection;
		class OnHostInfoCallback;
		class ClientPeer;
		class OnlineManager;
	};

	namespace ant
	{
		class AnimationUpdateArgs;
		class UpdatePoseSkeletonData;
		class QuatTransform;
		class UpdatePoseResultDataInternal;
		class UpdatePoseResultData;
		class UpdatePoseInitDataInternal;
		class PoseBlendDataInternal;
		class PoseInterpolationDataInternal;
		class AnimationSkeleton;
	};

	namespace vehicle
	{
		class VehicleState;
		class Engine;
		class GearboxState;
		class IGearbox;
		class Gearbox;
		class WheelReplicationState;
		class WheelState;
		class WheelFrameInterpolationState;
		class IWheel;
		class WingState;
		class IWing;
		class BodyDrag;
		class AeroDynamicPhysics;
		class Stabilizer;
		class IVehicle;
		class Input;
		class VehicleRender;
		class Vehicle;
	};


	class HudData;
	class ISocketManagerFactory;
	class Timer2;
	class TimeDemoBase;
	class ClientCallbacks;
	class VegetationManager;
	class CollisionState;
	class GearboxConfigData;
	class AeroDynamicPhysicsData;
	class WorldData;
	class PrefabBlueprint;
	class PhysicsEntityContainer;
	class EntityCollectionSegment;
	class SpottingComponentData;
	class WeaponComponent;
	class ComponentInfo;
	class EntityUpdateInfo;
	class CameraScene;
	class CharacterInput;
	class ClientSoldierBoundsChecker;
	class ClientWeaponComponent;
	class ClientWeaponComponentState;
	class ClientWeaponFiringReplicationState;
	class LockingControllerState;
	class AsyncRayCastQueue;
	class PartComponentData;
	class FocusPoint;





	class AeroDynamicPhysics;
	class AimAssist;
	class AimerModifierData;
	class AimingConstraints;
	class AimingPoseData;
	class AmmoConfigData;
	class AmmunitionDepot;
	class AntAnimatableComponent ;
	class AnimatedSoldierWeapon;
	class AnimatedSoldierWeaponOffsetModule;
	class AnimatedSoldierWeaponShootModule;
	class AnimatedSoldierWeaponSpeedModule;
	class AnimatedSoldierWeaponSprintModule;
	class AnimatedSoldierWeaponZoomModule;
	class AnimatedWeaponGS;
	class AnimationConfigurationShootModuleData;
	class ArrayTypeInfo ;
	class Asset;
	class AttributeArgument;
	class AttributeSpec;
	class AutoAimData;
	class AxisAlignedBox;
	class BitArray;
	class Blueprint;
	class BoltActionData;
	class BoneCollisionComponent;
	class BoneCollisionComponentData;
	class BoneCollisionData;
	class BoneFakePhysicsData;
	class BoneFakePhysics;
	class BorderInputNode;
	class BreathControlData;
	class BulletEntityData;
	class Camera;
	class CameraContext;
	class CameraData;
	class CameraManager;
	class CameraScene;
	class CharacterEntity;
	class CharacterEntityData;
	class CharacterPhysicsData;
	class CharacterPhysicsEntity;
	class CharacterPhysicsEntityCallbacks;
	class CharacterPhysicsEntityCollisionShapes;
	class CharacterPhysicsEntityContext;
	class CharacterPhysicsEntityState;
	class CharacterPoseConstraints;
	class CharacterPoseData;
	class CharacterCustomizationComponent;
	class CharacterCustomizationComponentState;
	class ClassInfo;
	class Client;
	class ClientAntAnimatableComponent;
	class ClientLevel;
	class ClientSettings;
	class ClientPickupEntity  ;
	class ClientGrenadeEntity ;
	class ClientExplosionPackEntity;
	class CharacterStateData;
	class CharacterStatePoseInfo;
	class CharacterThreadData;
	class ChassisComponent;
	class ClientAimingReplication;
	class ClientAnimatedSoldierWeaponHandler;
	class ClientBoneCollisionComponent;
	class ClientCameraContext;
	class ClientCharacterEntity;
	class ClientCharacterCustomizationComponent;
	class ClientChassisComponent;
	class ClientChassisComponentSimulation;
	class ClientChassisComponentReplication;
	class ClientChassisComponentPrediction;
	class ClientComponent;
	class ClientControllableEntity;
	class ClientEntryComponent;
	class ClientGameContext;
	class ClientGameEntity;
	class ClientGameView;
	class ClientGrenadeEntity ;
	class ClientPickupEntity  ;
	class ClientCameraComponent ;
	class ClientStanceFilterComponent ;
	class ClientEntryComponentSound;
	class ClientExplosionPackEntity ;
	class ClientGhostAndNetworkableGameEntity;
	class ClientHealthStateEntityManager;
	class ClientLockingController;
	class ClientPartComponent;
	class ClientPhysicsEntity;
	class ClientPlayer;
	class ClientPlayerManager;
	class ClientPlayerScoreManager;
	class ClientPlayerScore;
	class ClientPlayerManagerPlayer;
	class ClientPlayerView;
	class ClientRagdollComponent;
	class ClientSoldierBodyComponent;
	class ClientSoldierEntityState;
	class ClientSoldierBoundsChecker;	
	class ClientProximityHookImpl;
	class ClientSoldierBoundsCheckerState;
	class ClientSoldierAimingSimulation;
	class ClientSoldierEntity;
	class ClientSoldierPrediction;
	class ClientSoldierReplication;
	class ClientSoldierSimulation;
	class ClientSoldierWeapon;
	class ClientSoldierWeaponsComponent;
	class ClientSpottingTargetComponent;
	class ClientSpawnEntity;
	class ClientSubView;
	class ClientVehicleEntity;
	class ClientVehicleEntityHealth;
	class ClientVegetationManager;
	class ClientWeapon;
	class ClientWeaponFiringReplication;
	class ClientWeaponsState;
	class Component;
	class ComponentCollection;
	class ComponentData;
	class ConstWeakPtr;
	class ControllableEntity;
	class ControllableEntityData;
	class ControllableFinder;
	class CreationInfo;
	class CtrRefBase;
	class DataBusData;
	class DataContainer;
	class DebrisManager;
	class DebrisSystemSettings;
	class DebugRenderCmd;
	class DebugRenderStateCombo;
	class DebugRenderer2;
	class DebugRenderStats2;
	class DebugRenderCmd_Vertices;
	class DebugRenderVertex;
	class DeviceAction;
	class DxRenderer;
	class DynamicBitSet;
	struct eastl_arena_allocator;
	class EmitterManager;
	class EnlightenComponentData;
	class Entity;
	class EntityBus;
	class EntityBusData;
	class EntityBusPeer;
	class EntityCollectionSegment;
	class EntityCreator;
	class EntityData;
	class EntityGridQueryJobData;
	class EntityWorld;
	class EntryComponent;
	class EntryInput;
	class EntryInputActionMap;
	class EntryInputState;
	class EntryInputTranslator;
	class EventConnection;
	class EyePositionCallback;
	class FakePhysicsData;
	class FakePhysics;
	class FloatPhysicsData;
	class FieldAliasEntry;
	class FieldInfo;
	class FieldInfoImpl;
	class FileRef;
	class FireEffectData;
	class FireLogicData;
	class FiringDispersion;
	class FiringDispersionData;
	class FiringFunctionData;
	class FloatPhysics;
	class FrameInterpolationUpdateArgs;
	class FovEffect;
	class FreeCamera;
	class FreeCameraInput;
	class GameContext;
	class GameDataContainer;
	class GameEntity;
	class GameEntityData;
	class GameObjectData;
	class GamePhysicsEntityData;
	class GameRenderer;
	class GameRenderViewParams;
	class GameTime;
	class GameView;
	class GameWorld;
	class GeometryDeclarationDesc;
	class Guid;
	class HavokAsset;
	class HavokPhysicsManager;
	class HealthStateEntityManager;
	class HookCollisionData;
	class HookCollisionInfo;
	class HookProximityInfo;
	class HoldAndReleaseData;
	class IClientNetworkableGroupMember;
	class IClientSoldierHealthModule;
	class ICompareFilter;
	class IDebugRenderBackend;
	class IDebugRenderBackend;
	class IGameRenderer;
	class IEmitterCollisionHook ;
	class IResourceObject;
	class IInputFilter;
	class Input;
	class InputAction;
	class InputActionMap;
	class InputActionMapping;
	class InputActionMappingsData;
	class InputActions;
	class InputCache;
	class InputNode;
	class IKeyboard;
	class IMouse;
	class IPhantom;
	class IPhantomHook;
	class IPhantomBox;
	class IPhantomShape;
	class IMovingBody ;
	class IPhysicsRayCaster;
	class IPhysicsShape;
	class IPhysicsRenderer;
	class IPhysicsSphereShape;
	class IPhysicsManager;
	class IRotationBody;
	class IRigidBodyHook;
	class IResourceObject ;
	class IRenderResource ;
	class IScreenshotCallback;
	class ISocket;
	class ISocketAddress;
	class ISocketManager;
	class IStateRenderer;
	class ITexture;
	class ITypedObject;
	class ITypedObjectWithRefCount;
	class IUIComponent;
	class IUISystem;
	class JuiceScreenshotCallback ;
	class JuiceFrostbiteScreenshotModule;
	class JuiceScreenshotModule ;
	class JuiceScreenshotPlugin;
	class HavokPhysicsManager;
	class LagMod;
	class Level;
	class LevelData;
	class LevelDescription;
	class LevelSetup;
	class LevelSetupOption;
	class LinearTransform;
	class LinkConnection;
	class LockingController;
	class LockingControllerData;
	class LookConstraintsData;
	class MaterialContainerPair;
	class MaterialGridData;
	class MaterialGridManager;
	class MaterialInteractionGridRow;
	class MaterialRelationPropertyPair;
	class Main;
	class MemberInfo ;
	class MemberInfoFlags;
	class MemoryArena;
	class Mesh;
	class MeshMaterialVariation;
	class MeshMaterial;
	class MeshVariationSet;
	class MeshModel;
	class MeshSourceMaterial;
	class MeshAsset ;
	class MeshData;
	class MeshLayout ;
	class MeshSetLayout;
	class MeshSet;
	class MessageListener;
	class Minimap2DGeneratorPlugin;
	class MovingBodyState;
	class ModMultiplier;
	class ModuleInfo;
	class ModuleManager;
	class MotionController;
	class NoCaseStringLess;
	class NetworkManager;
	class ObjectBlueprint;
	class ObjectVariation;
	class OnlineId;
	class OverHeatData;
	class PartComponentData;
	class PathfindingBlob;
	class Pad;
	class PhysicsEntity;
	class PhysicsEntityContainer;
	class PhysicsEntityBase;
	class PhysicsEntityBaseRayCast;
	class PhysicsEntityData;
	class PhysicsEntityParts;
	class PhysicsEntityUserData;
	class PhysicsRenderParams;
	class PickupEntity ;
	class PitchModifier;
	class Player;
	class PlayerData;
	class PlayerManager;
	class PlayerScore;
	class PreloadedSubLevel;
	class PrefabBlueprint;
	class ProjectileBlueprint;
	class ProjectileEntityData;
	class PropertyConnection;
	class PropertyModificationListener;
	class ProximityHook;
	class ProximityHookImpl;
	class PunkbusterScreenshot;
	class QueryResult;
	class QuatTransform;
	class RadiosityMaterial;
	class RagdollCallbackHandler ;
	class RagdollComponent ;
	class RayCastHit;
	class RayCastResult;
	class ReplicatedBoolSignal;
	class RecoilData;
	class RecoilMod;
	class ReferenceObjectData;
	class RefillableAmmunitionDepot;
	class RenderScreenInfo;
	class RenderView;
	class RenderViewDesc;
	class RefCountBase ;
	class Rumble;
	class SafeQueryResult;
	class ShaderProgramPermutationInfo;
	class ServerPlayerView;
	class ScreenRenderer;
	class ScreenshotStatus ;
	class ServerGameEntity;
	class ServerPlayer;
	class ServerPlayerView;
	class ServerControllableEntity;
	class ServerSoldierEntity;
	class ServerCharacterEntity;
	class ScissorRect;
	class SimUpdateArgs;
	class ShotConfigData;
	class SkeletonAsset;
	class SkeletonCollisionData;
	class SkinnedMeshAsset;
	class Snowroller;
	class SocketData;
	class SoldierAimAssistData;
	class SoldierAimingEnvironment;
	class SoldierAimingSimulationData;
	class SoldierBodyComponent;
	class SoldierBoundsChecker;
	class SoldierEntity;
	class SoldierEntityData;
	class SoldierWeaponDispersion;
	class SoldierWeaponBlueprint;
	class SoldierWeaponsComponent;
	class StatsTracker;
	class SpatialEntity;
	class SpatialEntityData;
	class SpatialPrefabBlueprint;
	class SpawnReferenceObjectData;
	class SpeedModifierData;
	class SubLevel;
	class SubView;
	class SubWorldData;
	class SupportedShootingCallback;
	class SupportsWeakPtr;
	class SystemSettings;
	class TestDetails;
	class Test;
	class TestList;
	struct TypeInfoData ;
	struct TypeInfo;
	class TypeManager;
	class TargetCameraCallback;
	class TeamEntityData;
	class TeamInfo;
	class TerrainEntity;
	class Tool;
	class ToolData;
	class UINametag3dIcon;
	class UI3dIcon;
	class UINametagComp;
	class UINametag;
	class UIComponent;
	class UIHud;
	class Vec2;
	class Vec3;
	class Vec4;
	class VehicleEntity;
	class VehicleEntityHealth;
	class VehicleHealthZoneData;
	class VegetationSystemSettings;
	class Weapon;
	class WeaponInfo;
	class WeaponAimingConfigurationModifier;
	class WeaponAimingSimulationModifier;
	class WeaponAnimTypeModifier;
	class WeaponData;
	class WeaponFiring;
	class WeaponFiringCallbackHandler;
	class WeaponFiringCallbacks;
	class WeaponFiringData;
	class WeaponFiringDataModifier;
	class WeaponFiringEffectsModifier;
	class WeaponFiringShooter;
	class WeaponMagazineModifier;
	class WeaponMiscModifierSettings;
	class WeaponModifier;
	class WeaponModifierBase;
	class WeaponOffsetData;
	class WeaponProjectileModifier;
	class WeaponShotModifier;
	class WeaponSoundModifier;
	class WeaponSpeedData;
	class WeaponsState;
	class WeaponSuppressionData;
	class WeaponSway;
	class WeaponSwayCallbackImpl;
	class WeaponSwitching;
	class WeaponSwitchingCallbacks;
	class WeaponSwitchingState;
	class WeaponZoomModifier;
	class WorldData;
	class WorldRenderSettings;
	class ZoomLevelData;
	class ZoomLevelLockData;
	class ControlObjectState;
};

#endif