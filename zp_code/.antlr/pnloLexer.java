// Generated from c:/Users/admin/Desktop/qwe/Nson/zp_code/pnlo.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class pnloLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, STRING=12, NUMBER=13, WS=14;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "T__10", "STRING", "ESC", "UNICODE", "NAMETEE", "HEX", "SAFECODEPOINT", 
			"NUMBER", "INT", "EXP", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'>'", "'~'", "'='", "':'", "';'", "'['", "','", "']'", "'true'", 
			"'false'", "'null'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			"STRING", "NUMBER", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public pnloLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "pnlo.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\u000e\u008f\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002"+
		"\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002"+
		"\u0007\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002"+
		"\u000b\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e"+
		"\u0002\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011"+
		"\u0002\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014"+
		"\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002"+
		"\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0005\u000bO\b\u000b\n\u000b\f\u000bR\t\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\f\u0001\f\u0001\f\u0003\fY\b\f\u0001\r\u0001\r\u0001\r\u0001\r"+
		"\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f\u0001"+
		"\u0010\u0001\u0010\u0001\u0011\u0003\u0011h\b\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0004\u0011m\b\u0011\u000b\u0011\f\u0011n\u0003\u0011"+
		"q\b\u0011\u0001\u0011\u0003\u0011t\b\u0011\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0005\u0012y\b\u0012\n\u0012\f\u0012|\t\u0012\u0003\u0012~\b\u0012"+
		"\u0001\u0013\u0001\u0013\u0003\u0013\u0082\b\u0013\u0001\u0013\u0004\u0013"+
		"\u0085\b\u0013\u000b\u0013\f\u0013\u0086\u0001\u0014\u0004\u0014\u008a"+
		"\b\u0014\u000b\u0014\f\u0014\u008b\u0001\u0014\u0001\u0014\u0000\u0000"+
		"\u0015\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b\u0006"+
		"\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019\u0000\u001b"+
		"\u0000\u001d\u0000\u001f\u0000!\u0000#\r%\u0000\'\u0000)\u000e\u0001\u0000"+
		"\t\b\u0000\"\"//\\\\bbffnnrrtt\u0004\u000009AZ__az\u0003\u000009AFaf\u0003"+
		"\u0000\u0000\u001f\"\"\\\\\u0001\u000009\u0001\u000019\u0002\u0000EEe"+
		"e\u0002\u0000++--\u0003\u0000\t\n\r\r  \u0093\u0000\u0001\u0001\u0000"+
		"\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005\u0001\u0000"+
		"\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001\u0000\u0000"+
		"\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000"+
		"\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000\u0000"+
		"\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015\u0001\u0000\u0000\u0000"+
		"\u0000\u0017\u0001\u0000\u0000\u0000\u0000#\u0001\u0000\u0000\u0000\u0000"+
		")\u0001\u0000\u0000\u0000\u0001+\u0001\u0000\u0000\u0000\u0003-\u0001"+
		"\u0000\u0000\u0000\u0005/\u0001\u0000\u0000\u0000\u00071\u0001\u0000\u0000"+
		"\u0000\t3\u0001\u0000\u0000\u0000\u000b5\u0001\u0000\u0000\u0000\r7\u0001"+
		"\u0000\u0000\u0000\u000f9\u0001\u0000\u0000\u0000\u0011;\u0001\u0000\u0000"+
		"\u0000\u0013@\u0001\u0000\u0000\u0000\u0015F\u0001\u0000\u0000\u0000\u0017"+
		"K\u0001\u0000\u0000\u0000\u0019U\u0001\u0000\u0000\u0000\u001bZ\u0001"+
		"\u0000\u0000\u0000\u001d`\u0001\u0000\u0000\u0000\u001fb\u0001\u0000\u0000"+
		"\u0000!d\u0001\u0000\u0000\u0000#g\u0001\u0000\u0000\u0000%}\u0001\u0000"+
		"\u0000\u0000\'\u007f\u0001\u0000\u0000\u0000)\u0089\u0001\u0000\u0000"+
		"\u0000+,\u0005>\u0000\u0000,\u0002\u0001\u0000\u0000\u0000-.\u0005~\u0000"+
		"\u0000.\u0004\u0001\u0000\u0000\u0000/0\u0005=\u0000\u00000\u0006\u0001"+
		"\u0000\u0000\u000012\u0005:\u0000\u00002\b\u0001\u0000\u0000\u000034\u0005"+
		";\u0000\u00004\n\u0001\u0000\u0000\u000056\u0005[\u0000\u00006\f\u0001"+
		"\u0000\u0000\u000078\u0005,\u0000\u00008\u000e\u0001\u0000\u0000\u0000"+
		"9:\u0005]\u0000\u0000:\u0010\u0001\u0000\u0000\u0000;<\u0005t\u0000\u0000"+
		"<=\u0005r\u0000\u0000=>\u0005u\u0000\u0000>?\u0005e\u0000\u0000?\u0012"+
		"\u0001\u0000\u0000\u0000@A\u0005f\u0000\u0000AB\u0005a\u0000\u0000BC\u0005"+
		"l\u0000\u0000CD\u0005s\u0000\u0000DE\u0005e\u0000\u0000E\u0014\u0001\u0000"+
		"\u0000\u0000FG\u0005n\u0000\u0000GH\u0005u\u0000\u0000HI\u0005l\u0000"+
		"\u0000IJ\u0005l\u0000\u0000J\u0016\u0001\u0000\u0000\u0000KP\u0005\"\u0000"+
		"\u0000LO\u0003\u0019\f\u0000MO\u0003!\u0010\u0000NL\u0001\u0000\u0000"+
		"\u0000NM\u0001\u0000\u0000\u0000OR\u0001\u0000\u0000\u0000PN\u0001\u0000"+
		"\u0000\u0000PQ\u0001\u0000\u0000\u0000QS\u0001\u0000\u0000\u0000RP\u0001"+
		"\u0000\u0000\u0000ST\u0005\"\u0000\u0000T\u0018\u0001\u0000\u0000\u0000"+
		"UX\u0005\\\u0000\u0000VY\u0007\u0000\u0000\u0000WY\u0003\u001b\r\u0000"+
		"XV\u0001\u0000\u0000\u0000XW\u0001\u0000\u0000\u0000Y\u001a\u0001\u0000"+
		"\u0000\u0000Z[\u0005u\u0000\u0000[\\\u0003\u001f\u000f\u0000\\]\u0003"+
		"\u001f\u000f\u0000]^\u0003\u001f\u000f\u0000^_\u0003\u001f\u000f\u0000"+
		"_\u001c\u0001\u0000\u0000\u0000`a\u0007\u0001\u0000\u0000a\u001e\u0001"+
		"\u0000\u0000\u0000bc\u0007\u0002\u0000\u0000c \u0001\u0000\u0000\u0000"+
		"de\b\u0003\u0000\u0000e\"\u0001\u0000\u0000\u0000fh\u0005-\u0000\u0000"+
		"gf\u0001\u0000\u0000\u0000gh\u0001\u0000\u0000\u0000hi\u0001\u0000\u0000"+
		"\u0000ip\u0003%\u0012\u0000jl\u0005.\u0000\u0000km\u0007\u0004\u0000\u0000"+
		"lk\u0001\u0000\u0000\u0000mn\u0001\u0000\u0000\u0000nl\u0001\u0000\u0000"+
		"\u0000no\u0001\u0000\u0000\u0000oq\u0001\u0000\u0000\u0000pj\u0001\u0000"+
		"\u0000\u0000pq\u0001\u0000\u0000\u0000qs\u0001\u0000\u0000\u0000rt\u0003"+
		"\'\u0013\u0000sr\u0001\u0000\u0000\u0000st\u0001\u0000\u0000\u0000t$\u0001"+
		"\u0000\u0000\u0000u~\u00050\u0000\u0000vz\u0007\u0005\u0000\u0000wy\u0007"+
		"\u0004\u0000\u0000xw\u0001\u0000\u0000\u0000y|\u0001\u0000\u0000\u0000"+
		"zx\u0001\u0000\u0000\u0000z{\u0001\u0000\u0000\u0000{~\u0001\u0000\u0000"+
		"\u0000|z\u0001\u0000\u0000\u0000}u\u0001\u0000\u0000\u0000}v\u0001\u0000"+
		"\u0000\u0000~&\u0001\u0000\u0000\u0000\u007f\u0081\u0007\u0006\u0000\u0000"+
		"\u0080\u0082\u0007\u0007\u0000\u0000\u0081\u0080\u0001\u0000\u0000\u0000"+
		"\u0081\u0082\u0001\u0000\u0000\u0000\u0082\u0084\u0001\u0000\u0000\u0000"+
		"\u0083\u0085\u0007\u0004\u0000\u0000\u0084\u0083\u0001\u0000\u0000\u0000"+
		"\u0085\u0086\u0001\u0000\u0000\u0000\u0086\u0084\u0001\u0000\u0000\u0000"+
		"\u0086\u0087\u0001\u0000\u0000\u0000\u0087(\u0001\u0000\u0000\u0000\u0088"+
		"\u008a\u0007\b\u0000\u0000\u0089\u0088\u0001\u0000\u0000\u0000\u008a\u008b"+
		"\u0001\u0000\u0000\u0000\u008b\u0089\u0001\u0000\u0000\u0000\u008b\u008c"+
		"\u0001\u0000\u0000\u0000\u008c\u008d\u0001\u0000\u0000\u0000\u008d\u008e"+
		"\u0006\u0014\u0000\u0000\u008e*\u0001\u0000\u0000\u0000\r\u0000NPXgnp"+
		"sz}\u0081\u0086\u008b\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}