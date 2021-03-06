begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2013 Laszlo Papp<lpapp@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|qt_sine_table
specifier|const
name|qreal
name|qt_sine_table
index|[
name|QT_SINE_TABLE_SIZE
index|]
init|=
block|{
name|qreal
argument_list|(
literal|0.0
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.024541228522912288
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.049067674327418015
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.073564563599667426
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.098017140329560604
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.1224106751992162
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.14673047445536175
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.17096188876030122
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.19509032201612825
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.2191012401568698
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.24298017990326387
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.26671275747489837
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.29028467725446233
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.31368174039889152
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.33688985339222005
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.35989503653498811
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.38268343236508978
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.40524131400498986
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.42755509343028208
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.44961132965460654
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.47139673682599764
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.49289819222978404
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.51410274419322166
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.53499761988709715
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.55557023301960218
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.57580819141784534
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.59569930449243336
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.61523159058062682
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.63439328416364549
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.65317284295377676
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.67155895484701833
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.68954054473706683
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.70710678118654746
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.72424708295146689
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.74095112535495911
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.75720884650648446
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.77301045336273699
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.78834642762660623
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.80320753148064483
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.81758481315158371
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.83146961230254524
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.84485356524970701
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.85772861000027212
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.87008699110871135
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.88192126434835494
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.89322430119551532
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.90398929312344334
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.91420975570353069
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.92387953251128674
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.93299279883473885
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.94154406518302081
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.94952818059303667
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.95694033573220894
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.96377606579543984
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.97003125319454397
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.97570213003852857
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.98078528040323043
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.98527764238894122
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.98917650996478101
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.99247953459870997
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.99518472667219682
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.99729045667869021
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.99879545620517241
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.99969881869620425
argument_list|)
block|,
name|qreal
argument_list|(
literal|1.0
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.99969881869620425
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.99879545620517241
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.99729045667869021
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.99518472667219693
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.99247953459870997
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.98917650996478101
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.98527764238894122
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.98078528040323043
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.97570213003852857
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.97003125319454397
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.96377606579543984
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.95694033573220894
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.94952818059303667
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.94154406518302081
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.93299279883473885
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.92387953251128674
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.91420975570353069
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.90398929312344345
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.89322430119551521
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.88192126434835505
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.87008699110871146
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.85772861000027212
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.84485356524970723
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.83146961230254546
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.81758481315158371
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.80320753148064494
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.78834642762660634
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.7730104533627371
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.75720884650648468
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.74095112535495899
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.72424708295146689
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.70710678118654757
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.68954054473706705
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.67155895484701855
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.65317284295377664
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.63439328416364549
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.61523159058062693
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.59569930449243347
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.57580819141784545
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.55557023301960218
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.53499761988709715
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.51410274419322177
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.49289819222978415
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.47139673682599786
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.44961132965460687
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.42755509343028203
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.40524131400498992
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.38268343236508989
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.35989503653498833
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.33688985339222033
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.31368174039889141
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.29028467725446239
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.26671275747489848
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.24298017990326407
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.21910124015687005
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.19509032201612861
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.17096188876030122
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.1467304744553618
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.12241067519921635
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.098017140329560826
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.073564563599667732
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.049067674327417966
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.024541228522912326
argument_list|)
block|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.02454122852291208
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.049067674327417724
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.073564563599667496
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.09801714032956059
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.1224106751992161
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.14673047445536158
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.17096188876030097
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.19509032201612836
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.2191012401568698
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.24298017990326382
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.26671275747489825
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.29028467725446211
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.31368174039889118
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.33688985339222011
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.35989503653498811
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.38268343236508967
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.40524131400498969
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.42755509343028181
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.44961132965460665
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.47139673682599764
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.49289819222978393
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.51410274419322155
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.53499761988709693
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.55557023301960196
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.57580819141784534
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.59569930449243325
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.61523159058062671
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.63439328416364527
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.65317284295377653
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.67155895484701844
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.68954054473706683
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.70710678118654746
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.72424708295146678
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.74095112535495888
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.75720884650648423
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.77301045336273666
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.78834642762660589
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.80320753148064505
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.81758481315158382
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.83146961230254524
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.84485356524970701
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.85772861000027201
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.87008699110871135
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.88192126434835494
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.89322430119551521
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.90398929312344312
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.91420975570353047
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.92387953251128652
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.93299279883473896
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.94154406518302081
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.94952818059303667
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.95694033573220882
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.96377606579543984
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.97003125319454397
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.97570213003852846
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.98078528040323032
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.98527764238894111
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.9891765099647809
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.99247953459871008
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.99518472667219693
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.99729045667869021
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.99879545620517241
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.99969881869620425
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|1.0
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.99969881869620425
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.99879545620517241
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.99729045667869021
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.99518472667219693
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.99247953459871008
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.9891765099647809
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.98527764238894122
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.98078528040323043
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.97570213003852857
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.97003125319454397
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.96377606579543995
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.95694033573220894
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.94952818059303679
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.94154406518302092
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.93299279883473907
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.92387953251128663
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.91420975570353058
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.90398929312344334
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.89322430119551532
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.88192126434835505
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.87008699110871146
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.85772861000027223
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.84485356524970723
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.83146961230254546
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.81758481315158404
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.80320753148064528
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.78834642762660612
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.77301045336273688
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.75720884650648457
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.74095112535495911
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.724247082951467
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.70710678118654768
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.68954054473706716
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.67155895484701866
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.65317284295377709
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.63439328416364593
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.61523159058062737
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.59569930449243325
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.57580819141784523
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.55557023301960218
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.53499761988709726
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.51410274419322188
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.49289819222978426
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.47139673682599792
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.44961132965460698
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.42755509343028253
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.40524131400499042
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.38268343236509039
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.359895036534988
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.33688985339222
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.31368174039889152
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.2902846772544625
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.26671275747489859
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.24298017990326418
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.21910124015687016
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.19509032201612872
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.17096188876030177
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.14673047445536239
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.12241067519921603
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.098017140329560506
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.073564563599667412
argument_list|)
block|,
name|qreal
argument_list|(
operator|-
literal|0.049067674327418091
argument_list|)
block|,
name|qreal
argument_list|(
argument|-
literal|0.024541228522912448
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
