# README #

Pastas/arquivos importantes:

quartus/ -> arquivos de projeto utilizado no Quartus

src/ -> arquivos VHDL que descrevem o filtro IIR

     -> iir_core.vhd -> core do FILTRO IIR em VHDL

     -> iir_package.vhd -> "header" do filtro VHDL. Contem coeficientes, depth e numero de bits fracao/interiro

     -> iir_avalon.vhd  -> core que cria interface entre o filtro e o controlador de memoria via protocolo AVALON.


scripts -> Pasta que contem scripts para geracao do iir_package.vhd atraves dos filtros previamente descritos em C.

driver/ -> Pasta que contem drivers para utilizacao do filtro. Estes arquivos devem estar dentro da placa de desenvolvimento. Pasta esta desatualizada: Driver foi separado em .c e .h e atualmente está rodando na placa. Falta atualizar aqui.