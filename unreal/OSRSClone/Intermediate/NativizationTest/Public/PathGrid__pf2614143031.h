#pragma once
#include "Blueprint/BlueprintSupport.h"
#include "Runtime/CoreUObject/Public/UObject/NoExportTypes.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "PathTile__pf2614143031.h"
class UBillboardComponent;
class USceneComponent;
class APathTile_C__pf2614143031;
#include "PathGrid__pf2614143031.generated.h"
UCLASS(config=Engine, Blueprintable, BlueprintType, meta=(ReplaceConverted="/Game/Blueprints/Pathfinding/PathGrid.PathGrid_C", OverrideNativeName="PathGrid_C"))
class APathGrid_C__pf2614143031 : public AActor
{
public:
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Billboard"))
	UBillboardComponent* bpv__Billboard__pf;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Scene"))
	USceneComponent* bpv__Scene__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Grid Location", Category="Grid", MultiLine="true", OverrideNativeName="GridLocation"))
	FVector bpv__GridLocation__pf;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Grid Size World", Category="Grid", MultiLine="true", OverrideNativeName="GridSizeWorld"))
	FVector2D bpv__GridSizeWorld__pf;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Grid Bounds Color", Category="Debug", MultiLine="true", OverrideNativeName="GridBoundsColor"))
	FLinearColor bpv__GridBoundsColor__pf;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Show Grid", Category="Debug", MultiLine="true", OverrideNativeName="ShowGrid"))
	bool bpv__ShowGrid__pf;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Tile Size", Category="Grid", MultiLine="true", ExposeOnSpawn="true", OverrideNativeName="TileSize"))
	float bpv__TileSize__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Tile Gap", Category="Grid", MultiLine="true", OverrideNativeName="TileGap"))
	float bpv__TileGap__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Tile Data", Category="Grid", MultiLine="true", OverrideNativeName="TileData"))
	TMap<FVector2D,APathTile_C__pf2614143031*> bpv__TileData__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Selected Tile", Category="Path", MultiLine="true", OverrideNativeName="SelectedTile"))
	APathTile_C__pf2614143031* bpv__SelectedTile__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Hovered Tile", Category="Path", MultiLine="true", OverrideNativeName="HoveredTile"))
	APathTile_C__pf2614143031* bpv__HoveredTile__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Path ", Category="Path", MultiLine="true", OverrideNativeName="Path_"))
	TArray<APathTile_C__pf2614143031*> bpv__Path___pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_CustomEvent_Tile_1"))
	APathTile_C__pf2614143031* b0l__K2Node_CustomEvent_Tile_1__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_CustomEvent_Tile"))
	APathTile_C__pf2614143031* b0l__K2Node_CustomEvent_Tile__pf;
	APathGrid_C__pf2614143031(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	void bpf__ExecuteUbergraph_PathGrid__pf_0(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_PathGrid__pf_1(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_PathGrid__pf_2(int32 bpp__EntryPoint__pf);
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="OnTileHovered"))
	virtual void bpf__OnTileHovered__pf(APathTile_C__pf2614143031* bpp__Tile__pf);
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="OnTileSelected"))
	virtual void bpf__OnTileSelected__pf(APathTile_C__pf2614143031* bpp__Tile__pf);
	UFUNCTION(meta=(Comment="/** Event when play begins for this actor. */", DisplayName="BeginPlay", ToolTip="Event when play begins for this actor.", CppFromBpEvent, OverrideNativeName="ReceiveBeginPlay"))
	virtual void bpf__ReceiveBeginPlay__pf();
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(Category, OverrideNativeName="GetOrigin"))
	virtual void bpf__GetOrigin__pf(/*out*/ FVector& bpp__Position__pf);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(Category, OverrideNativeName="GetTileCount"))
	virtual void bpf__GetTileCount__pf(/*out*/ int32& bpp__GridTileX__pf, /*out*/ int32& bpp__GridTileY__pf);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(Category, OverrideNativeName="TraceTile"))
	virtual bool  bpf__TraceTile__pf(const FVector bpp__Position__pf__const, ETraceTypeQuery bpp__Channel__pf);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(Category, OverrideNativeName="GetRealTileSize"))
	virtual void bpf__GetRealTileSize__pf(/*out*/ float& bpp__Size__pf);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(Category, OverrideNativeName="TilePositionFromCoordinate"))
	virtual void bpf__TilePositionFromCoordinate__pf(int32 bpp__X__pf, int32 bpp__Y__pf, /*out*/ FVector& bpp__Position__pf);
	UFUNCTION(BlueprintCallable, meta=(Category="Default", OverrideNativeName="CreateMapData"))
	virtual void bpf__CreateMapData__pf();
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(Category, OverrideNativeName="GetNeighbors"))
	virtual void bpf__GetNeighbors__pf(APathTile_C__pf2614143031* bpp__Tile__pf, /*out*/ TArray<APathTile_C__pf2614143031*>& bpp__Neighbors__pf);
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="CreateTiles"))
	virtual void bpf__CreateTiles__pf();
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(Category, OverrideNativeName="GetEstimatedCostToTarget"))
	virtual void bpf__GetEstimatedCostToTarget__pf(FVector2D bpp__CurrentIndex__pf, FVector2D bpp__TargetIndex__pf, /*out*/ int32& bpp__Cost__pf);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(Category, OverrideNativeName="GetDistance"))
	virtual void bpf__GetDistance__pf(APathTile_C__pf2614143031* bpp__TileA__pf, APathTile_C__pf2614143031* bpp__TileB__pf, /*out*/ int32& bpp__Distance__pf);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(Category, OverrideNativeName="GetTileFromIndex"))
	virtual void bpf__GetTileFromIndex__pf(FVector2D const& bpp__Index__pf__const, /*out*/ APathTile_C__pf2614143031*& bpp__Tile__pf);
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="FindPathToTarget"))
	virtual void bpf__FindPathToTarget__pf(APathTile_C__pf2614143031* bpp__Start__pf, APathTile_C__pf2614143031* bpp__Target__pf);
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="RetracePath"))
	virtual void bpf__RetracePath__pf(APathTile_C__pf2614143031* bpp__Target__pf, APathTile_C__pf2614143031* bpp__Start__pf);
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="Clear Path"))
	virtual void bpf__ClearxPath__pfT();
public:
};
