begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsound.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SOUND
end_ifndef
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|"qsound_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|servers
specifier|static
name|QList
argument_list|<
name|QAuServer
modifier|*
argument_list|>
modifier|*
name|servers
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QAuServer
name|QAuServer
operator|::
name|QAuServer
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{
if|if
condition|(
operator|!
name|servers
condition|)
name|servers
operator|=
operator|new
name|QList
argument_list|<
name|QAuServer
operator|*
argument_list|>
expr_stmt|;
name|servers
operator|->
name|prepend
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QAuServer
name|QAuServer
operator|::
name|~
name|QAuServer
parameter_list|()
block|{
name|servers
operator|->
name|removeAll
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|servers
operator|->
name|count
argument_list|()
operator|==
literal|0
condition|)
block|{
operator|delete
name|servers
expr_stmt|;
name|servers
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|play
name|void
name|QAuServer
operator|::
name|play
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|)
block|{
name|QSound
name|s
argument_list|(
name|filename
argument_list|)
decl_stmt|;
name|play
argument_list|(
operator|&
name|s
argument_list|)
expr_stmt|;
block|}
end_function
begin_function_decl
specifier|extern
name|QAuServer
modifier|*
name|qt_new_audio_server
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|server
specifier|static
name|QAuServer
modifier|&
name|server
parameter_list|()
block|{
if|if
condition|(
operator|!
name|servers
condition|)
name|qt_new_audio_server
argument_list|()
expr_stmt|;
return|return
operator|*
name|servers
operator|->
name|first
argument_list|()
return|;
block|}
end_function
begin_class
DECL|class|QSoundPrivate
class|class
name|QSoundPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
public|public:
DECL|function|QSoundPrivate
name|QSoundPrivate
parameter_list|(
specifier|const
name|QString
modifier|&
name|fname
parameter_list|)
member_init_list|:
name|filename
argument_list|(
name|fname
argument_list|)
member_init_list|,
name|bucket
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|looprem
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|looptotal
argument_list|(
literal|1
argument_list|)
block|{     }
DECL|function|~QSoundPrivate
name|~
name|QSoundPrivate
parameter_list|()
block|{
operator|delete
name|bucket
expr_stmt|;
block|}
DECL|member|filename
name|QString
name|filename
decl_stmt|;
DECL|member|bucket
name|QAuBucket
modifier|*
name|bucket
decl_stmt|;
DECL|member|looprem
name|int
name|looprem
decl_stmt|;
DECL|member|looptotal
name|int
name|looptotal
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QSound     \brief The QSound class provides access to the platform audio facilities.      \ingroup multimedia     \inmodule QtWidgets      Qt provides the most commonly required audio operation in GUI     applications: asynchronously playing a sound file. This is most     easily accomplished using the static play() function:      \snippet doc/src/snippets/code/src_gui_kernel_qsound.cpp 0      Alternatively, create a QSound object from the sound file first     and then call the play() slot:      \snippet doc/src/snippets/code/src_gui_kernel_qsound.cpp 1      Once created a QSound object can be queried for its fileName() and     total number of loops() (i.e. the number of times the sound will     play). The number of repetitions can be altered using the     setLoops() function. While playing the sound, the loopsRemaining()     function returns the remaining number of repetitions. Use the     isFinished() function to determine whether the sound has finished     playing.      Sounds played using a QSound object may use more memory than the     static play() function, but it may also play more immediately     (depending on the underlying platform audio facilities). Use the     static isAvailable() function to determine whether sound     facilities exist on the platform. Which facilities that are     actually used varies:      \table     \header \o Platform \o Audio Facility     \row     \o Microsoft Windows     \o The underlying multimedia system is used; only WAVE format sound files     are supported.     \row     \o X11     \o The \l{ftp://ftp.x.org/contrib/audio/nas/}{Network Audio System}     is used if available, otherwise all operations work silently. NAS     supports WAVE and AU files.     \row     \o Mac OS X     \o NSSound is used. All formats that NSSound supports, including QuickTime formats,     are supported by Qt for Mac OS X.     \row     \o Qt for Embedded Linux     \o A built-in mixing sound server is used, accessing \c /dev/dsp     directly. Only the WAVE format is supported.     \row     \o Symbian     \o CMdaAudioPlayerUtility is used. All formats that Symbian OS or devices support     are supported also by Qt.     \endtable      Note that QSound does not support \l{resources.html}{resources}.     This might be fixed in a future Qt version. */
end_comment
begin_comment
comment|/*!     Plays the sound stored in the file specified by the given \a filename.      \sa stop(), loopsRemaining(), isFinished() */
end_comment
begin_function
DECL|function|play
name|void
name|QSound
operator|::
name|play
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|)
block|{
name|server
argument_list|()
operator|.
name|play
argument_list|(
name|filename
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Constructs a QSound object from the file specified by the given \a     filename and with the given \a parent.      This may use more memory than the static play() function, but it     may also play more immediately (depending on the underlying     platform audio facilities).      \sa play() */
end_comment
begin_constructor
DECL|function|QSound
name|QSound
operator|::
name|QSound
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QSoundPrivate
argument_list|(
name|filename
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{
name|server
argument_list|()
operator|.
name|init
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys this sound object. If the sound is not finished playing,     the stop() function is called before the sound object is     destructed.      \sa stop(), isFinished() */
end_comment
begin_destructor
DECL|function|~QSound
name|QSound
operator|::
name|~
name|QSound
parameter_list|()
block|{
if|if
condition|(
operator|!
name|isFinished
argument_list|()
condition|)
name|stop
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns true if the sound has finished playing; otherwise returns false.      \warning On Windows this function always returns true for unlooped sounds. */
end_comment
begin_function
DECL|function|isFinished
name|bool
name|QSound
operator|::
name|isFinished
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSound
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|looprem
operator|==
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \overload      Starts playing the sound specified by this QSound object.      The function returns immediately.  Depending on the platform audio     facilities, other sounds may stop or be mixed with the new     sound. The sound can be played again at any time, possibly mixing     or replacing previous plays of the sound.      \sa fileName() */
end_comment
begin_function
DECL|function|play
name|void
name|QSound
operator|::
name|play
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSound
argument_list|)
expr_stmt|;
name|d
operator|->
name|looprem
operator|=
name|d
operator|->
name|looptotal
expr_stmt|;
name|server
argument_list|()
operator|.
name|play
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of times the sound will play.      \sa loopsRemaining(), setLoops() */
end_comment
begin_function
DECL|function|loops
name|int
name|QSound
operator|::
name|loops
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSound
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|looptotal
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the remaining number of times the sound will loop (this     value decreases each time the sound is played).      \sa loops(), isFinished() */
end_comment
begin_function
DECL|function|loopsRemaining
name|int
name|QSound
operator|::
name|loopsRemaining
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSound
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|looprem
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QSound::setLoops(int number)      Sets the sound to repeat the given \a number of times when it is     played.      Note that passing the value -1 will cause the sound to loop     indefinitely.      \sa loops() */
end_comment
begin_function
DECL|function|setLoops
name|void
name|QSound
operator|::
name|setLoops
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSound
argument_list|)
expr_stmt|;
name|d
operator|->
name|looptotal
operator|=
name|n
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the filename associated with this QSound object.      \sa QSound() */
end_comment
begin_function
DECL|function|fileName
name|QString
name|QSound
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSound
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|filename
return|;
block|}
end_function
begin_comment
comment|/*!     Stops the sound playing.      Note that on Windows the current loop will finish if a sound is     played in a loop.      \sa play() */
end_comment
begin_function
DECL|function|stop
name|void
name|QSound
operator|::
name|stop
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSound
argument_list|)
expr_stmt|;
name|server
argument_list|()
operator|.
name|stop
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|d
operator|->
name|looprem
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns true if sound facilities exist on the platform; otherwise     returns false.      If no sound is available, all QSound operations work silently and     quickly. An application may choose either to notify the user if     sound is crucial to the application or to operate silently without     bothering the user.      Note: On Windows this always returns true because some sound card     drivers do not implement a way to find out whether it is available     or not. */
end_comment
begin_function
DECL|function|isAvailable
name|bool
name|QSound
operator|::
name|isAvailable
parameter_list|()
block|{
return|return
name|server
argument_list|()
operator|.
name|okay
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the internal bucket record of sound \a s to \a b, deleting     any previous setting. */
end_comment
begin_function
DECL|function|setBucket
name|void
name|QAuServer
operator|::
name|setBucket
parameter_list|(
name|QSound
modifier|*
name|s
parameter_list|,
name|QAuBucket
modifier|*
name|b
parameter_list|)
block|{
operator|delete
name|s
operator|->
name|d_func
argument_list|()
operator|->
name|bucket
expr_stmt|;
name|s
operator|->
name|d_func
argument_list|()
operator|->
name|bucket
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the internal bucket record of sound \a s. */
end_comment
begin_function
DECL|function|bucket
name|QAuBucket
modifier|*
name|QAuServer
operator|::
name|bucket
parameter_list|(
name|QSound
modifier|*
name|s
parameter_list|)
block|{
return|return
name|s
operator|->
name|d_func
argument_list|()
operator|->
name|bucket
return|;
block|}
end_function
begin_comment
comment|/*!     Decrements the QSound::loopRemaining() value for sound \a s,     returning the result. */
end_comment
begin_function
DECL|function|decLoop
name|int
name|QAuServer
operator|::
name|decLoop
parameter_list|(
name|QSound
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
name|s
operator|->
name|d_func
argument_list|()
operator|->
name|looprem
operator|>
literal|0
condition|)
operator|--
name|s
operator|->
name|d_func
argument_list|()
operator|->
name|looprem
expr_stmt|;
return|return
name|s
operator|->
name|d_func
argument_list|()
operator|->
name|looprem
return|;
block|}
end_function
begin_comment
comment|/*!     Initializes the sound. The default implementation does nothing. */
end_comment
begin_function
DECL|function|init
name|void
name|QAuServer
operator|::
name|init
parameter_list|(
name|QSound
modifier|*
parameter_list|)
block|{ }
end_function
begin_destructor
DECL|function|~QAuBucket
name|QAuBucket
operator|::
name|~
name|QAuBucket
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn bool QSound::available()      Use the isAvailable() function instead. */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SOUND
end_comment
end_unit
