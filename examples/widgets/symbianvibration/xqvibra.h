begin_unit
begin_ifndef
ifndef|#
directive|ifndef
name|XQVIBRA_H
end_ifndef
begin_define
DECL|macro|XQVIBRA_H
define|#
directive|define
name|XQVIBRA_H
end_define
begin_comment
comment|// INCLUDES
end_comment
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_comment
comment|// FORWARD DECLARATIONS
end_comment
begin_decl_stmt
DECL|variable|XQVibraPrivate
name|class
name|XQVibraPrivate
decl_stmt|;
end_decl_stmt
begin_comment
comment|// CLASS DECLARATION
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|XQVibra
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
specifier|static
specifier|const
name|int
name|InfiniteDuration
operator|=
literal|0
block|;
specifier|static
specifier|const
name|int
name|MaxIntensity
operator|=
literal|100
block|;
specifier|static
specifier|const
name|int
name|MinIntensity
operator|=
operator|-
literal|100
block|;      enum
name|Error
block|{
name|NoError
operator|=
literal|0
block|,
name|OutOfMemoryError
block|,
name|ArgumentError
block|,
name|VibraInUseError
block|,
name|HardwareError
block|,
name|TimeOutError
block|,
name|VibraLockedError
block|,
name|AccessDeniedError
block|,
name|UnknownError
operator|=
operator|-
literal|1
block|}
block|;      enum
name|Status
block|{
name|StatusNotAllowed
operator|=
literal|0
block|,
name|StatusOff
block|,
name|StatusOn
block|}
block|;
name|XQVibra
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|XQVibra
argument_list|()
block|;
name|XQVibra
operator|::
name|Status
name|currentStatus
argument_list|()
specifier|const
block|;
name|XQVibra
operator|::
name|Error
name|error
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|statusChanged
argument_list|(
argument|XQVibra::Status status
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|bool
name|start
argument_list|(
argument|int duration = InfiniteDuration
argument_list|)
block|;
name|bool
name|stop
argument_list|()
block|;
name|bool
name|setIntensity
argument_list|(
argument|int intensity
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|XQVibraPrivate
block|;
name|XQVibraPrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// XQVIBRA_H
end_comment
begin_comment
comment|// End of file
end_comment
end_unit
