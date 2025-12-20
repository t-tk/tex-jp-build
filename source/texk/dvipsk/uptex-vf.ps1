# Public domain.
# You may freely use, modify and/or distribute this file.

$srcdir = "..\..\source\texk\dvipsk"
$testdata = "$srcdir\testdata"

$env:TEXFONTS = ".;$testdata"
$env:TEXPSHEADERS = "$testdata"
$env:SOURCE_DATE_EPOCH = 1588474800

Remove-item .\upj*.vf,.\upj*.ofm,.\upjf*_*.ps

Copy-Item -Path $testdata\upjf_full.vf -Destination .\upjf.vf
Copy-Item -Path $testdata\upjv_full.vf -Destination .\upjv.vf

..\Debug\bin\dvips.exe -d 4 $testdata\upjf.dvi -o upjf.ps -u $testdata\upjf.map

Move-Item upjf.ps upjf_full.ps

Copy-Item -Path $testdata\upjf_omit.vf -Destination .\upjf.vf -Force
Copy-Item -Path $testdata\upjv_omit.vf -Destination .\upjv.vf -Force
Copy-Item -Path $testdata\upjf-g00.ofm -Destination .\upjf-g.ofm
Copy-Item -Path $testdata\upjv-g00.ofm -Destination .\upjv-g.ofm

..\Debug\bin\dvips.exe -d 4 $testdata\upjf.dvi -o upjf.ps -u $testdata\upjf.map

Move-Item upjf.ps upjf_omit.ps


Copy-Item -Path $testdata\upjf-r00.ofm -Destination .\upjf-r.ofm -Force
Copy-Item -Path $testdata\upjv-r00.ofm -Destination .\upjv-r.ofm -Force

..\Debug\bin\dvips.exe -d 4 $testdata\upjf.dvi -o upjf.ps -u $testdata\upjf.map

Move-Item upjf.ps upjf_omit2.ps


Remove-item .\upjf-r.ofm,.\upjv-r.ofm

Copy-Item -Path $testdata\upjf1_full.vf -Destination .\upjf.vf -Force
Copy-Item -Path $testdata\upjv_full.vf -Destination .\upjv.vf -Force

..\Debug\bin\dvips.exe -d 4 $testdata\upjf.dvi -o upjf1.ps -u $testdata\upjf.map

Move-Item upjf1.ps upjf1_full.ps

Copy-Item -Path $testdata\upjf1_omit.vf -Destination .\upjf.vf -Force
Copy-Item -Path $testdata\upjv_omit.vf -Destination .\upjv.vf -Force
Copy-Item -Path $testdata\upjf1-r.tfm -Destination .\upjf-r.tfm -Force

..\Debug\bin\dvips.exe -d 4 $testdata\upjf.dvi -o upjf1.ps -u $testdata\upjf.map

Move-Item upjf1.ps upjf1_omit.ps

Copy-Item -Path $testdata\upjf-r00.ofm -Destination .\upjf-r.ofm -Force
Copy-Item -Path $testdata\upjv-r00.ofm -Destination .\upjv-r.ofm -Force

..\Debug\bin\dvips.exe -d 4 $testdata\upjf.dvi -o upjf1.ps -u $testdata\upjf.map

Move-Item upjf1.ps upjf1_omit2.ps


Compare-Object upjf_omit.ps upjf_full.ps
Compare-Object upjf_omit2.ps upjf_full.ps
Compare-Object upjf1_omit.ps upjf1_full.ps
Compare-Object upjf1_omit2.ps upjf1_full.ps
