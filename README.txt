Repositorio contem todos os arquivos necessarios para validação de filtros em FPGA, utilizando o kit De0-Nano (CycloneV SoC)

Arquivos para sintese do filtro em FPGA estao no diretorio> filter_validation/
  -> Utilize scripts, na pasta scripts/ para gerar arquivos .vhd (iir_package.vhd)
  -> gen_filter_config.sh <filtro> gera arquivo de configuração do filtro em arquivo do tipo .yaml
  -> gen_vhdl_package <config.yaml> gera arquivo iir_package.vhd, contendo as configurações do filtro em VHDL
  -> Foi utilizado o software Quartus II + QSys para compilação e sintese do filtro.

Arquivos para execução de programas de teste do filtro estao no diretorio> filterOverflow/
 -> Esta pasta contem os arquivos do programa "framework" alterados para comunicação com a FPGA.
    -> filterSimul.c foi adicionado a funcao hw_filterSimul()
    -> main.c foi adicionado o mapeamento em memoria das regioes de configuração e dados de saída do filtro
    -> filterEval.c executa a funcao hw_filterSimul() ao inves da filterSimul()


Observacoes e resultados preliminares:
-> Filtro em VHDL executa (a[i]*x[i]... - b[i]*y[i]...), diferentemente da abordagem utilzada no filtro codificado em c (a[i]*x[i]... + -b[i]*y[i]...)
-> Filtro demora mais a ser testado.
   -> hp2C_D10_F6 (ARM: ~60 segs; ARM+FPGA: ~300 segs)

Limitações:
-> Core do filtro em VHDL ainda não possui suporte para mais de um estagio. 


