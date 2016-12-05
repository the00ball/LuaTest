
---- C++ Bindind Class Test ----

print("Cálculo do Valor da Parcela")
print("Plano de Parcelamento de R$ 30.000,00 a 0,99% de juros a.m")

c = Calc(0,0,0)
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
