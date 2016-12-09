# LuaTest
  
This project applies a c++ binding into lua script, where the c++ class ***Calc*** can be accessed by Lua script.

Lua Script
```lua
print("Cálculo do Valor da Parcela")
print("Plano de Parcelamento de R$ 30.000,00 a 0,99% de juros a.m")

c = Calc()
c:SetI(0.0099)
c:SetPv(30000)
meses = {6,12,18,24,30,36,42,48,54,60}

print("-----------------------------------------")
print("|    Meses      |      Valor da Parcela |")
print("-----------------------------------------")
for i,n in ipairs(meses) do
  c:SetN(n)
  print("|",n,"|",c:CalcPmt(), "|")  
end
print("-----------------------------------------")
```

## Enviroment

This repository is pre-configured for Eclipse CDT enviroment: Eclipse Neon. 1a Release(4.6.1).(not mandatory)

## Dependencies

* Linux enviroment; (Developed over Ubuntu 16.10)
* Eclipse Neon. 1a Release(4.6.1) or more recent version; (not mandatory)
* CDT enviroment; (not mandatory)
* liblua5.3-devLib.;

## Testing the Program

In a command line terminal
type ***./LuaTest cpp_binding_test.lua*** and voilá:

```
Cálculo do Valor da Parcela
Plano de Parcelamento de R$ 30.000,00 a 0,99% de juros a.m
-----------------------------------------
|    Meses      |      Valor da Parcela |
-----------------------------------------
|	6	        |   5174.6721986431     |
|	12	        |	2663.7798413113     |
|	18	        |	1827.7895841691	    |
|	24	        |	1410.5235780201	    |
|	30	        |	1160.7458488807	    |
|	36	        |	994.71073824652	    |
|	42	        |	876.52696668694	    |
|	48	        |	788.24865034294	    |
|	54	        |	719.90564027691	    |
|	60	        |	665.51565866318	    |
-----------------------------------------
```
