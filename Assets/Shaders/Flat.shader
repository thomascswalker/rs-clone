Shader "Tutorials/OverlayShader"
{
    Properties
    {
    }
 
    SubShader
    {
        Pass
        {
            CGPROGRAM
 
            #pragma vertex vertexFunc
            #pragma fragment fragmentFunc
            #include "UnityCG.cginc"
 
            struct v2f
            {
                fixed4 color : COLOR0;
                float4 pos : SV_POSITION;
                float3 normal : NORMAL;
            };
    
            v2f vertexFunc(appdata_full v)
            {
                v2f o;

                o.pos = UnityObjectToClipPos(v.vertex);
                o.normal = mul(unity_ObjectToWorld, v.normal);
                o.color = v.color;

                return o;
            }
    
            fixed4 fragmentFunc(v2f i) : COLOR
            {
                return i.color;
            }
    
            ENDCG
        }
    }
}
