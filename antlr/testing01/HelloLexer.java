// Generated from Hello.g4 by ANTLR 4.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class HelloLexer extends Lexer {
	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, ID=2, WS=3;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] tokenNames = {
		"<INVALID>",
		"'hello'", "ID", "WS"
	};
	public static final String[] ruleNames = {
		"T__0", "ID", "WS"
	};


	public HelloLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Hello.g4"; }

	@Override
	public String[] getTokenNames() { return tokenNames; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2\5\30\b\1\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\3\2\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\4\6\4\23\n\4\r\4\16"+
		"\4\24\3\4\3\4\2\2\5\3\3\5\4\7\5\3\2\4\5\2\62;C\\c|\5\2\13\f\17\17\"\""+
		"\30\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\3\t\3\2\2\2\5\17\3\2\2\2\7\22"+
		"\3\2\2\2\t\n\7j\2\2\n\13\7g\2\2\13\f\7n\2\2\f\r\7n\2\2\r\16\7q\2\2\16"+
		"\4\3\2\2\2\17\20\t\2\2\2\20\6\3\2\2\2\21\23\t\3\2\2\22\21\3\2\2\2\23\24"+
		"\3\2\2\2\24\22\3\2\2\2\24\25\3\2\2\2\25\26\3\2\2\2\26\27\b\4\2\2\27\b"+
		"\3\2\2\2\4\2\24\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}