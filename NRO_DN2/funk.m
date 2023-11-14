(* ::Package:: *)

funk[n_]:=Block[{koor,z=0,notritocke={},zunajtocke={}},Do[koor=RandomReal[{-2,2},2];
If[Norm[koor]<=2,{z++,notritocke=Append[notritocke,koor]},zunajtocke=Append[zunajtocke,koor]],n];
{N[4*z/n],notritocke,zunajtocke}];
