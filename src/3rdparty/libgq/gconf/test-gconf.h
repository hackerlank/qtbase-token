begin_unit
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|"GConfItem"
end_include
begin_comment
comment|// Helper class for listening to signals
end_comment
begin_decl_stmt
name|class
name|SignalListener
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|int
name|numberOfCalls
block|;
name|SignalListener
argument_list|()
operator|:
name|numberOfCalls
argument_list|(
literal|0
argument_list|)
block|{     }
name|public
name|slots
operator|:
name|void
name|valueChanged
argument_list|()
block|{
name|numberOfCalls
operator|++
block|;     }
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Tests for the public API
end_comment
begin_decl_stmt
name|class
name|GConfItemTests
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
comment|// Stored pointers etc.
name|private
operator|:
name|GConfItem
operator|*
name|boolItem
block|;
name|GConfItem
operator|*
name|intItem
block|;
name|GConfItem
operator|*
name|stringItem
block|;
name|GConfItem
operator|*
name|doubleItem
block|;
name|GConfItem
operator|*
name|stringListItem
block|;
name|GConfItem
operator|*
name|intListItem
block|;
name|GConfItem
operator|*
name|doubleListItem
block|;
name|GConfItem
operator|*
name|boolListItem
block|;
name|GConfItem
operator|*
name|unsetBeforeItem
block|;
name|GConfItem
operator|*
name|unsetAfterItem
block|;
name|SignalListener
operator|*
name|signalSpy
block|;
name|QTimer
name|timer
block|;
name|bool
name|timed_out
block|;
comment|// Tests
name|private
name|slots
operator|:
comment|// Init and cleanup helper functions
name|void
name|initTestCase
argument_list|()
block|;
name|void
name|cleanupTestCase
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|cleanup
argument_list|()
block|;
name|void
name|timeout
argument_list|()
block|;
comment|// Public API
name|void
name|path
argument_list|()
block|;
name|void
name|external_values
argument_list|()
block|;
name|void
name|set_bool
argument_list|()
block|;
name|void
name|set_int
argument_list|()
block|;
name|void
name|set_string
argument_list|()
block|;
name|void
name|set_unicode_string
argument_list|()
block|;
name|void
name|set_double
argument_list|()
block|;
name|void
name|set_string_list
argument_list|()
block|;
name|void
name|set_int_list
argument_list|()
block|;
name|void
name|set_double_list
argument_list|()
block|;
name|void
name|set_bool_list
argument_list|()
block|;
name|void
name|unset
argument_list|()
block|;
name|void
name|get_default
argument_list|()
block|;
name|void
name|list_dirs
argument_list|()
block|;
name|void
name|list_entries
argument_list|()
block|;
name|void
name|propagate
argument_list|()
block|;
name|void
name|set_external
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Useful if you need to process some events until a condition becomes
end_comment
begin_comment
comment|// true.
end_comment
begin_define
DECL|macro|QVERIFY_TIMEOUT
define|#
directive|define
name|QVERIFY_TIMEOUT
parameter_list|(
name|msecs
parameter_list|,
name|expr
parameter_list|)
define|\
value|do {                                                                    \         timed_out = false;                                                  \         timer.start(msecs);                                                 \         while (!timed_out&& !(expr)) {                                     \             QCoreApplication::processEvents(QEventLoop::WaitForMoreEvents); \         }                                                                   \         QVERIFY((expr));                                                    \     } while(0)
end_define
end_unit
